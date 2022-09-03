#include "DerammoTestScriptInstance.h"

#include <godot/gdnative_interface.h>

#include "DerammoTestLanguage.h"
#include "DerammoTestScript.h"
#include "DerammoTestThreadContext.h"

// ReSharper disable CppClangTidyMiscMisplacedConst
// ReSharper disable CppMemberFunctionMayBeConst

class DerammoTestScriptInstanceGlue {
public:
    static GDNativeExtensionScriptInstanceInfo instance_info;

private:
    class Bindings {
    public:
        Bindings() {
            instance_info.get_script_func = s_get_script;
            instance_info.free_func = s_free;
            instance_info.has_method_func = s_has_method;
            instance_info.call_func = s_call;
        }
    };

    static Bindings _bindings;

    static GDNativeObjectPtr s_get_script(GDNativeExtensionScriptInstanceDataPtr void_this) {
        return reinterpret_cast<DerammoTestScriptInstance*>(void_this)
            ->get_script();
    }

    static void s_free(GDNativeExtensionScriptInstanceDataPtr void_this) {
        delete reinterpret_cast<DerammoTestScriptInstance*>(void_this);
    }

    static GDNativeBool s_has_method(GDNativeExtensionScriptInstanceDataPtr void_this,
                                     const GDNativeStringNamePtr p_name) {
        return reinterpret_cast<DerammoTestScriptInstance*>(void_this)->has_method(
            p_name);
    }

    static void s_call(GDNativeExtensionScriptInstanceDataPtr void_this,
                       const GDNativeStringNamePtr p_method,
                       const GDNativeVariantPtr* p_args,
                       const GDNativeInt p_argument_count,
                       GDNativeVariantPtr r_return, GDNativeCallError* r_error) {
        reinterpret_cast<DerammoTestScriptInstance*>(void_this)->call(
            p_method, p_args, p_argument_count, r_return, r_error);
    }
};

DerammoTestScriptInstance::DerammoTestScriptInstance(const DerammoTestScript* parent, godot::Object* host_object) {
    _parent = parent;
    _host_object = host_object;
}

GDNativeObjectPtr DerammoTestScriptInstance::get_script() const {
    return const_cast<DerammoTestScript*>(_parent);
}

void DerammoTestScriptInstance::call(const GDNativeStringNamePtr p_method, const GDNativeVariantPtr* p_args,
                                     const int64_t p_argument_count, GDNativeVariantPtr r_return,
                                     GDNativeCallError* r_error) {
    const godot::StringName* method =
        reinterpret_cast<const godot::StringName*>(p_method);
    if ((*method) == _ready) {
        // TODO: set up some stuff like severity and the error message once we have those
        DerammoTestLanguage::current_thread().set_example_stuff();
        _parent->language->debug_break();
        r_error->error = GDNATIVE_CALL_OK;
    } else {
        r_error->error = GDNATIVE_CALL_ERROR_INVALID_METHOD;
    }
    r_error->argument = -1;
    r_error->expected = -1;
}

uint8_t DerammoTestScriptInstance::has_method(const GDNativeStringNamePtr p_name) {
    const godot::StringName* name =
        reinterpret_cast<const godot::StringName*>(p_name);
    return (*name) == _ready ? 1 : 0;
}

GDNativeScriptInstancePtr DerammoTestScriptInstance::create_instance(const DerammoTestScript* parent,
                                                                     godot::Object* host_object) {
    return godot::internal::gdn_interface->script_instance_create(
        &DerammoTestScriptInstanceGlue::instance_info,
        new DerammoTestScriptInstance(parent, host_object));
}

GDNativeExtensionScriptInstanceInfo DerammoTestScriptInstanceGlue::instance_info;
DerammoTestScriptInstanceGlue::Bindings DerammoTestScriptInstanceGlue::_bindings;

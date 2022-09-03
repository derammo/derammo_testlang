#include "DerammoTestScript.h"

#include <fstream>

#include "DerammoTestLanguage.h"
#include "DerammoTestScriptInstance.h"

#include <godot_cpp/classes/script_language_thread_context_extension.hpp>
#include <godot_cpp/classes/file.hpp>

bool DerammoTestScript::_can_instantiate() const {
    return true;
}

bool DerammoTestScript::_has_source_code() const {
    return false;
}

bool DerammoTestScript::_has_method(const StringName& method) const {
    return false;
}

bool DerammoTestScript::_is_tool() const {
    return false;
}

bool DerammoTestScript::_is_valid() const {
    return true;
}

ScriptLanguage* DerammoTestScript::_get_language() const {
    return language;
}

bool DerammoTestScript::_has_script_signal(const StringName& signal) const {
    return false;
}

Array DerammoTestScript::_get_script_signal_list() const {
    return Array();
}

Array DerammoTestScript::_get_script_method_list() const {
    return Array();
}

Array DerammoTestScript::_get_script_property_list() const {
    return Array();
}

Dictionary DerammoTestScript::_get_constants() const {
    return Dictionary();
}

Array DerammoTestScript::_get_members() const {
    return Array();
}

bool DerammoTestScript::_is_placeholder_fallback_enabled() const {
    return false;
}

Ref<Script> DerammoTestScript::_get_base_script() const {
    return Ref<Script>();
}

StringName DerammoTestScript::_get_instance_base_type() const {
    return StringName("Object");
}

String DerammoTestScript::_get_source_code() const {
    return String("This language does not use source code");
}

void DerammoTestScript::_set_source_code(const String& code) {
    // no code
}

void DerammoTestScript::_update_exports() {
    // nothing to do
}

void* DerammoTestScript::_instance_create(Object* for_object) const {
    return DerammoTestScriptInstance::create_instance(this, for_object);
}

Array DerammoTestScript::_get_documentation() const {
    return Array();
}

bool DerammoTestScript::_has_property_default_value(const StringName&) const {
    return false;
}

Variant DerammoTestScriptResourceLoader::_load(const String& p_path, const String& p_original_path,
                                               bool p_use_sub_threads, int64_t p_cache_mode) const {
    return language->module_create_script();
}

PackedStringArray DerammoTestScriptResourceLoader::_get_recognized_extensions() const {
    PackedStringArray extensions;
    extensions.append(DerammoTestLanguage::module_get_extension_constant());
    return extensions;
}

bool DerammoTestScriptResourceLoader::_handles_type(const StringName& p_type) const {
    return (p_type == DerammoTestLanguage::module_get_type_constant());
}

String DerammoTestScriptResourceLoader::_get_resource_type(const String& p_path) const {
    String el = p_path.get_extension().to_lower();
    if (el == DerammoTestLanguage::module_get_extension_constant()) {
        return DerammoTestLanguage::module_get_type_constant();
    }
    return "";
}

PackedStringArray DerammoTestScriptResourceLoader::_get_dependencies(const String& path, bool add_types) const {
    return PackedStringArray();
}

int64_t DerammoTestScriptResourceSaver::_save(const Ref<Resource>& p_resource, const String& path, int64_t flags) {
    Ref<File> out;
    out.instantiate();
    // will trigger https://github.com/godotengine/godot/issues/64455
    out->open(path, File::ModeFlags::WRITE);
    out->store_string("dummy");
    out->close();
    return OK;
}

bool DerammoTestScriptResourceSaver::_recognize(const Ref<Resource>& p_resource) const {
    // REVISIT: expanded for Natvis development
    const String resource_class = p_resource->get_class();
    const String our_class = DerammoTestScript::get_class_static();
    return (resource_class == our_class);
}

PackedStringArray DerammoTestScriptResourceSaver::_get_recognized_extensions(const Ref<Resource>& resource) const {
    PackedStringArray extensions;
    extensions.append(DerammoTestLanguage::module_get_extension_constant());
    return extensions;
}

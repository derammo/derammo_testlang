#pragma once

#include "DerammoTestLang.h"

#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/core/object.hpp>

class DerammoTestScript;

// ReSharper disable CppClangTidyMiscMisplacedConst
// ReSharper disable CppMemberFunctionMayBeConst

class DerammoTestScriptInstance {
    const DerammoTestScript* _parent;
    godot::Object* _host_object;
    godot::StringName _ready = "_ready";

public:
    explicit DerammoTestScriptInstance(const DerammoTestScript* parent,
                                       godot::Object* host_object);

    GDNativeObjectPtr get_script() const;

    void call(const GDNativeStringNamePtr p_method,
              const GDNativeVariantPtr* p_args, const int64_t p_argument_count,
              GDNativeVariantPtr r_return, GDNativeCallError* r_error);

    uint8_t has_method(const GDNativeStringNamePtr p_name);

    static GDNativeScriptInstancePtr create_instance(const DerammoTestScript* parent, godot::Object* host_object);
};

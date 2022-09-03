#include "DerammoTestLanguage.h"

#include "DerammoTestScript.h"
#include "DerammoTestThreadContext.h"
#include "DerammoTestScriptInstance.h"

#include <godot_cpp/classes/script_language_thread_context_extension.hpp>

void DerammoTestLanguage::_thread_enter() {
}

void DerammoTestLanguage::_thread_exit() {
}

void DerammoTestLanguage::_frame() {
}

String DerammoTestLanguage::_get_name() const {
    return "TestLanguage";
}

void DerammoTestLanguage::_init() {
}

String DerammoTestLanguage::module_get_type_constant() {
    return "Script";
}

String DerammoTestLanguage::_get_type() const {
    return module_get_type_constant();
}

String DerammoTestLanguage::module_get_extension_constant() {
    return "testlanguage";
}

String DerammoTestLanguage::_get_extension() const {
    return module_get_extension_constant();
}

void DerammoTestLanguage::_finish() {
}

PackedStringArray DerammoTestLanguage::_get_reserved_words() const {
    return PackedStringArray();
}

bool DerammoTestLanguage::_is_control_flow_keyword(const String& keyword) const {
    return false;
}

PackedStringArray DerammoTestLanguage::_get_comment_delimiters() const {
    return PackedStringArray();
}

PackedStringArray DerammoTestLanguage::_get_string_delimiters() const {
    return PackedStringArray();
}

Array DerammoTestLanguage::_get_built_in_templates(const StringName& object) const {
    return Array();
}

bool DerammoTestLanguage::_is_using_templates() {
    return false;
}

Dictionary DerammoTestLanguage::_validate(const String& script, const String& path, bool validate_functions,
                                          bool validate_errors, bool validate_warnings,
                                          bool validate_safe_lines) const {
    Dictionary validation;
    validation["valid"] = true;
    return validation;
}

String DerammoTestLanguage::_validate_path(const String& path) const {
    return "";
}

DerammoTestScript* DerammoTestLanguage::_do_create_script() const {
    DerammoTestScript* created = memnew(DerammoTestScript());
    created->language = const_cast<DerammoTestLanguage*>(this);
    return created;
}

Object* DerammoTestLanguage::_create_script() const {
    return _do_create_script();
}

bool DerammoTestLanguage::_has_named_classes() const {
    return false;
}

bool DerammoTestLanguage::_supports_builtin_mode() const {
    return false;
}

bool DerammoTestLanguage::_supports_documentation() const {
    return false;
}

bool DerammoTestLanguage::_can_inherit_from_file() const {
    return false;
}

int64_t DerammoTestLanguage::_find_function(const String& class_name, const String& function_name) const {
    return 0;
}

String DerammoTestLanguage::_make_function(const String& class_name, const String& function_name,
                                           const PackedStringArray& function_args) const {
    return "";
}

bool DerammoTestLanguage::_overrides_external_editor() {
    return false;
}

Dictionary DerammoTestLanguage::_complete_code(const String& code, const String& path, Object* owner) const {
    return Dictionary();
}

Dictionary DerammoTestLanguage::_lookup_code(const String& code, const String& symbol, const String& path,
                                             Object* owner) const {
    return Dictionary();
}

String DerammoTestLanguage::_auto_indent_code(const String& code, int64_t from_line, int64_t to_line) const {
    return "";
}

void DerammoTestLanguage::_add_global_constant(const StringName& name, const Variant& value) {
}

void DerammoTestLanguage::_add_named_global_constant(const StringName& name, const Variant& value) {
}

void DerammoTestLanguage::_remove_named_global_constant(const StringName& name) {
}

Dictionary DerammoTestLanguage::_debug_get_globals(int64_t max_subitems, int64_t max_depth) const {
    return Dictionary();
}

void DerammoTestLanguage::_reload_all_scripts() {
}

void DerammoTestLanguage::_reload_tool_script(const Ref<Script>& script, bool soft_reload) {
}

PackedStringArray DerammoTestLanguage::_get_recognized_extensions() const {
    PackedStringArray extensions;
    extensions.append(_get_extension());
    return extensions;
}

Array DerammoTestLanguage::_get_public_functions() const {
    return Array();
}

Dictionary DerammoTestLanguage::_get_public_constants() const {
    return Dictionary();
}

Array DerammoTestLanguage::_get_public_annotations() const {
    return Array();
}

void DerammoTestLanguage::_profiling_start() {
}

void DerammoTestLanguage::_profiling_stop() {
}

bool DerammoTestLanguage::_handles_global_class_type(const String& type) const {
    return false;
}

Dictionary DerammoTestLanguage::_get_global_class_name(const String& path) const {
    return Dictionary();
}

Ref<Script> DerammoTestLanguage::module_create_script() const {
    DerammoTestScript* created = _do_create_script();
    Ref<Script> ret = Ref<Script>(created);
    // https://github.com/godotengine/godot-cpp/issues/652
    ret->reference();
    return ret;
}

Ref<Script> DerammoTestLanguage::_make_template(const String& _template, const String& class_name,
                                                const String& base_class_name) const {
    return module_create_script();
}

// Uncounted reference, owned by Godot and will be deallocated when the corresponding thread exits, or
// (for main) when the languages are shut down.  In any case, it will be valid when we are running and we don't
// need to clean it up.
thread_local DerammoTestThreadContext* t_thread_context = nullptr;

Ref<ScriptLanguageThreadContextExtension> DerammoTestLanguage::_create_thread_context() const {
    // We may actually have already created it while running some code before the debugger ever asked for it.
    return Ref<ScriptLanguageThreadContextExtension>(&current_thread());
}

DerammoTestThreadContext& DerammoTestLanguage::current_thread() {
    if (t_thread_context == nullptr) {
        t_thread_context = memnew(DerammoTestThreadContext);
        // https://github.com/godotengine/godot-cpp/issues/652
        t_thread_context->reference();
    }
    return *t_thread_context;
}

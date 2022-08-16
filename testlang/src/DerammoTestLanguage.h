#ifndef DERAMMOTESTLANGUAGE_H
#define DERAMMOTESTLANGUAGE_H

#include <godot_cpp/classes/script_language_extension.hpp>
#include <godot_cpp/classes/script.hpp>

using namespace godot;

class DerammoTestScript;

class DerammoTestLanguage : public ScriptLanguageExtension
{
	GDCLASS(DerammoTestLanguage, ScriptLanguageExtension)

protected:
	static void _bind_methods()
	{
		// no code
	}

	DerammoTestScript* _do_create_script() const;

public:
	// Internal code for use in extension module.
	static String module_get_extension_constant();
	static String module_get_type_constant();
	Ref<Script> module_create_script() const;

public:
	void _thread_enter() override;
	void _thread_exit() override;
	void _frame() override;

	String _get_name() const override;
	void _init() override;
	String _get_type() const override;
	String _get_extension() const override;
	void _finish() override;
	PackedStringArray _get_reserved_words() const override;
	bool _is_control_flow_keyword(const String& keyword) const override;
	PackedStringArray _get_comment_delimiters() const override;
	PackedStringArray _get_string_delimiters() const override;
	Array _get_built_in_templates(const StringName& object) const override;
	bool _is_using_templates() override;
	Dictionary _validate(const String& script, const String& path, bool validate_functions, bool validate_errors,
	                     bool validate_warnings, bool validate_safe_lines) const override;
	String _validate_path(const String& path) const override;
	Object* _create_script() const override;
	bool _has_named_classes() const override;
	bool _supports_builtin_mode() const override;
	bool _supports_documentation() const override;
	bool _can_inherit_from_file() const override;
	int64_t _find_function(const String& class_name, const String& function_name) const override;
	String _make_function(const String& class_name, const String& function_name,
	                      const PackedStringArray& function_args) const override;
	bool _overrides_external_editor() override;
	Dictionary _complete_code(const String& code, const String& path, Object* owner) const override;
	Dictionary _lookup_code(const String& code, const String& symbol, const String& path, Object* owner) const override;
	String _auto_indent_code(const String& code, int64_t from_line, int64_t to_line) const override;
	void _add_global_constant(const StringName& name, const Variant& value) override;
	void _add_named_global_constant(const StringName& name, const Variant& value) override;
	void _remove_named_global_constant(const StringName& name) override;
	Dictionary _debug_get_globals(int64_t max_subitems, int64_t max_depth) const override;
	void _reload_all_scripts() override;
	void _reload_tool_script(const Ref<Script>& script, bool soft_reload) override;
	PackedStringArray _get_recognized_extensions() const override;
	Array _get_public_functions() const override;
	Dictionary _get_public_constants() const override;
	Array _get_public_annotations() const override;
	void _profiling_start() override;
	void _profiling_stop() override;
	bool _handles_global_class_type(const String& type) const override;
	Dictionary _get_global_class_name(const String& path) const override;

	Ref<Script> _make_template(const String& _template, const String& class_name, const String& base_class_name) const override;
	
	~DerammoTestLanguage() override = default;
};

#endif // DERAMMOTESTLANGUAGE_H

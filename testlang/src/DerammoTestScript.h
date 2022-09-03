#pragma once

#include "DerammoTestLang.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/script_extension.hpp>
#include <godot_cpp/classes/resource_format_loader.hpp>
#include <godot_cpp/classes/resource_format_saver.hpp>
#include <godot_cpp/templates/list.hpp>

using namespace godot;

class DerammoTestScript : public ScriptExtension {
	GDCLASS(DerammoTestScript, ScriptExtension)

	friend class DerammoTestLanguage;

	DerammoTestLanguage* language = nullptr;

protected:
	static void _bind_methods() {
		// no code
	}


public:
	bool _can_instantiate() const override;
	bool _has_source_code() const override;
	bool _has_method(const StringName& method) const override;
	bool _is_tool() const override;
	bool _is_valid() const override;
	ScriptLanguage* _get_language() const override;
	bool _has_script_signal(const StringName& signal) const override;
	Array _get_script_signal_list() const override;
	Array _get_script_method_list() const override;
	Array _get_script_property_list() const override;
	Dictionary _get_constants() const override;
	Array _get_members() const override;
	bool _is_placeholder_fallback_enabled() const override;
	Array _get_documentation() const override;
	bool _has_property_default_value(const StringName& name) const override;
	Ref<Script> _get_base_script() const override;
	StringName _get_instance_base_type() const override;
	String _get_source_code() const override;
	void _set_source_code(const String& code) override;
	void _update_exports() override;

	void* _instance_create(Object* for_object) const override;
};

class DerammoTestScriptResourceLoader : public ResourceFormatLoader {
	GDCLASS(DerammoTestScriptResourceLoader, ResourceFormatLoader)

	friend void initialize_derammo_testlang_module(ModuleInitializationLevel p_level);
	DerammoTestLanguage* language = nullptr;

protected:
	static void _bind_methods() {
		// no code
	}

public:
	PackedStringArray _get_recognized_extensions() const override;
	bool _handles_type(const StringName& p_type) const override;
	String _get_resource_type(const String& path) const override;
	PackedStringArray _get_dependencies(const String& path, bool add_types) const override;
	Variant _load(const String& path, const String& original_path, bool use_sub_threads,
	              int64_t cache_mode) const override;
};

class DerammoTestScriptResourceSaver : public ResourceFormatSaver {
	GDCLASS(DerammoTestScriptResourceSaver, ResourceFormatSaver)

protected:
	static void _bind_methods() {
		// no code
	}

public:
	int64_t _save(const Ref<Resource>& p_resource, const String& path, int64_t flags) override;
	bool _recognize(const Ref<Resource>& resource) const override;
	PackedStringArray _get_recognized_extensions(const Ref<Resource>& resource) const override;
};


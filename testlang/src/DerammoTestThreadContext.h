#pragma once

#include <godot_cpp/classes/script_language_thread_context_extension.hpp>

class DerammoTestThreadContext : public godot::ScriptLanguageThreadContextExtension {
    GDCLASS(DerammoTestThreadContext, godot::ScriptLanguageThreadContextExtension)

protected:
    static void _bind_methods();

public:
    void set_example_stuff() {
        // example
    }

    // API
    // XXX missing severity in API, need to convert to int
    // XXX missing _debug_get_thread_id
    // XXX missing _debug_is_main_thread
    godot::String _debug_get_error() const override;
    int64_t _debug_get_stack_level_count() const override;
    int64_t _debug_get_stack_level_line(int64_t level) const override;
    godot::String _debug_get_stack_level_function(int64_t level) const override;
    godot::Dictionary _debug_get_stack_level_locals(int64_t level, int64_t max_subitems,
                                                    int64_t max_depth) const override;
    godot::Dictionary _debug_get_stack_level_members(int64_t level, int64_t max_subitems,
                                                     int64_t max_depth) const override;
    void* _debug_get_stack_level_instance(int64_t level) const override;
    godot::String _debug_parse_stack_level_expression(
        int64_t level, const godot::String& expression,
        int64_t max_subitems,
        int64_t max_depth) const override;
    godot::Array _debug_get_current_stack_info() const override;
};

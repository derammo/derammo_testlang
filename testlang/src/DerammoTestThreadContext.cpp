#include "DerammoTestThreadContext.h"

#include "DerammoTestLanguage.h"

void DerammoTestThreadContext::_bind_methods() {
}

godot::String DerammoTestThreadContext::_debug_get_error() const {
    return "example_error";
}

int64_t DerammoTestThreadContext::_debug_get_stack_level_count() const {
    return 3;
}

int64_t DerammoTestThreadContext::_debug_get_stack_level_line(int64_t level) const {
    switch (level) {
    case 0:
        return 1234;
    case 1:
        return 56;
    case 2:
        return 7;
    default:
        return -1;
    }
}

godot::String DerammoTestThreadContext::_debug_get_stack_level_function(int64_t level) const {
    switch (level) {
    case 0:
        return "top_function";
    case 1:
        return "middle_function";
    case 2:
        return "bottom_function";
    default:
        return "should_never_be_returned";
    }
}

godot::Dictionary DerammoTestThreadContext::_debug_get_stack_level_locals(int64_t level, int64_t max_subitems,
                                                                          int64_t max_depth) const {
    // TODO: implement some examples
    return godot::Dictionary();
}

godot::Dictionary DerammoTestThreadContext::_debug_get_stack_level_members(int64_t level, int64_t max_subitems,
                                                                           int64_t max_depth) const {
    // TODO: implement some examples
    return godot::Dictionary();
}

void* DerammoTestThreadContext::_debug_get_stack_level_instance(int64_t level) const {
    // TODO: study how to make this do anything demonstrable, we probably need to actually run to create multiple instances at different stack frames.
    return nullptr;
}

godot::String DerammoTestThreadContext::_debug_parse_stack_level_expression(int64_t level, const godot::String& expression,
                                                                     int64_t max_subitems, int64_t max_depth) const {
    return "";
}

// REVISIT remove this virtual in the extension and just build it from the constituent parts
godot::Array DerammoTestThreadContext::_debug_get_current_stack_info() const {
    const int64_t frames = _debug_get_stack_level_count();
    godot::Array result;
    for (int64_t frame = 0; frame < frames; frame++) {
        godot::Dictionary frame_result;
        // TODO: use our stack level instance once we have one
        frame_result['file'] =
            godot::String("example.") + DerammoTestLanguage::module_get_extension_constant();
        frame_result['line'] = _debug_get_stack_level_line(frame);
        frame_result['func'] = _debug_get_stack_level_function(frame);
        result.append(frame_result);
    }
    return godot::Array();
}
////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "input_float.hpp"

namespace yq::tachyon::im {

    namespace {
        const void* stepptr(const input_float_t& options)
        {
            if(options.step > 0.)
                return &options.step;
            return nullptr;
        }

        const void* stepfastptr(const input_float_t& options)
        {
            if(options.step_fast > 0.)
                return &options.step_fast;
            return nullptr;
        }
    }

    bool    input(const char* label, float& v, const input_float_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::InputFloat(label, &v, opts.step, opts.step_fast, opts.format, opts.flags);
    }

    bool    input(const char* label, unsigned n, float* v, const input_float_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::InputScalarN(label, ImGuiDataType_Float, v, n, stepptr(opts), stepfastptr(opts), opts.format, opts.flags);
    }

    bool    input(const char* label, Quaternion3F&v, const input_float_quaternion_t& opts)
    {
        return input(label, 4, (float*) &v, { 
            .flags      = opts.flags,
            .format     = opts.format,
            .labelless  = opts.labelless,
            .max        = opts.max,
            .min        = opts.min,
            .step       = opts.step,
            .step_fast  = opts.step_fast
        });
    }
    
    bool    input(const char* label, RangeF&v, const input_float_t& opts)
    {
        return input(label, 2, (float*) &v, opts);
    }

    bool    input(const char* label, RGB3F&v, const input_float_t& opts)
    {
        return input(label, 3, (float*) &v, opts);
    }
    
    bool    input(const char* label, RGBA4F&v, const input_float_t& opts)
    {
        return input(label, 4, (float*) &v, opts);
    }

    bool    input(const char* label, Size2F&v, const input_float_t& opts)
    {
        return input(label, 2, (float*) &v, opts);
    }

    bool    input(const char* label, Size3F&v, const input_float_t& opts)
    {
        return input(label, 3, (float*) &v, opts);
    }
    
    bool    input(const char* label, Size4F&v, const input_float_t& opts)
    {
        return input(label, 4, (float*) &v, opts);
    }

    bool    input(const char* label, UV2F&v, const input_float_t& opts)
    {
        return input(label, 2, (float*) &v, opts);
    }

    bool    input(const char* label, UVW3F&v, const input_float_t& opts)
    {
        return input(label, 3, (float*) &v, opts);
    }
    
    bool    input(const char* label, Vector1F&v, const input_float_t& opts)
    {
        return input(label, v.x, opts);
    }
    
    bool    input(const char* label, Vector2F&v, const input_float_t& opts)
    {
        return input(label, 2, (float*) &v, opts);
    }

    bool    input(const char* label, Vector3F&v, const input_float_t& opts)
    {
        return input(label, 3, (float*) &v, opts);
    }
    
    bool    input(const char* label, Vector4F&v, const input_float_t& opts)
    {
        return input(label, 4, (float*) &v, opts);
    }

}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "input_double.hpp"
#include <yq/math/Range.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/shape/Size3.hpp>
#include <yq/shape/Size4.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon::im {

    namespace {
        const void* stepptr(const input_double_t& options)
        {
            if(options.step > 0.)
                return &options.step;
            return nullptr;
        }

        const void* stepfastptr(const input_double_t& options)
        {
            if(options.step_fast > 0.)
                return &options.step_fast;
            return nullptr;
        }
    }

    bool    input(const char* label, double& v, const input_double_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::InputDouble(label, &v, opts.step, opts.step_fast, opts.format, opts.flags);
    }

    bool    input(const char* label, unsigned n, double* v, const input_double_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::InputScalarN(label, ImGuiDataType_Double, v, n, stepptr(opts), stepfastptr(opts), opts.format, opts.flags);
    }

    bool    input(const char* label, Quaternion3D&v, const input_double_quaternion_t& opts)
    {
        return input(label, 4, (double*) &v, { 
            .flags      = opts.flags,
            .format     = opts.format,
            .labelless  = opts.labelless,
            .max        = opts.max,
            .min        = opts.min,
            .step       = opts.step,
            .step_fast  = opts.step_fast
        });
    }
    
    bool    input(const char* label, RangeD&v, const input_double_t& opts)
    {
        return input(label, 2, (double*) &v, opts);
    }
    
    bool    input(const char* label, Size2D&v, const input_double_t& opts)
    {
        return input(label, 2, (double*) &v, opts);
    }
    
    bool    input(const char* label, Size3D&v, const input_double_t& opts)
    {
        return input(label, 3, (double*) &v, opts);
    }
    
    bool    input(const char* label, Size4D&v, const input_double_t& opts)
    {
        return input(label, 4, (double*) &v, opts);
    }
    
    bool    input(const char* label, UV2D&v, const input_double_t& opts)
    {
        return input(label, 2, (double*) &v, opts);
    }
    
    bool    input(const char* label, UVW3D&v, const input_double_t& opts)
    {
        return input(label, 3, (double*) &v, opts);
    }
    
    bool    input(const char* label, Vector1D&v, const input_double_t& opts)
    {
        return input(label, v.x, opts);
    }
    
    bool    input(const char* label, Vector2D&v, const input_double_t& opts)
    {
        return input(label, 2, (double*) &v, opts);
    }
    
    bool    input(const char* label, Vector3D&v, const input_double_t& opts)
    {
        return input(label, 3, (double*) &v, opts);
    }
    
    bool    input(const char* label, Vector4D&v, const input_double_t& opts)
    {
        return input(label, 4, (double*) &v, opts);
    }
    
}

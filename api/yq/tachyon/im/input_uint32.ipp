////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "input_uint32.hpp"
#include <yq/vector/Vector1.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon::im {
    namespace {
        const void* stepptr(const input_uint32_t& options)
        {
            if(options.step > 0)
                return &options.step;
            return nullptr;
        }

        const void* stepfastptr(const input_uint32_t& options)
        {
            if(options.step_fast > 0)
                return &options.step_fast;
            return nullptr;
        }
    }

    bool    input(const char* label, unsigned& v, const input_uint32_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::InputScalar(label, ImGuiDataType_U32, &v, stepptr(opts), stepfastptr(opts), opts.format, opts.flags);
    }

    bool    input(const char* label, unsigned n, uint32_t*v, const input_uint32_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::InputScalarN(label, ImGuiDataType_U32, v, n, stepptr(opts), stepfastptr(opts), opts.format, opts.flags);
    }
    
    bool    input(const char* label, Vector1U&v, const input_uint32_t& opts)
    {
        return input(label, v.x, opts);
    }
    
    bool    input(const char* label, Vector2U&v, const input_uint32_t& opts)
    {
        return input(label, 2, (uint32_t*) &v, opts);
    }
    
    bool    input(const char* label, Vector3U&v, const input_uint32_t& opts)
    {
        return input(label, 3, (uint32_t*) &v, opts);
    }
    
    bool    input(const char* label, Vector4U&v, const input_uint32_t& opts)
    {
        return input(label, 4, (uint32_t*) &v, opts);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "text.hpp"
#include <yq/core/Any.hpp>
#include <yq/math/glm.hpp>
#include <yq/math/UV.hpp>
#include <yq/math/UVW.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/shape/Size3.hpp>
#include <yq/shape/Size4.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>
#include <filesystem>

namespace yq::tachyon::im {
    void    text(bool v)
    {
        ImGui::TextUnformatted( v ? "true" : "false" );
    }
    
    void    text(double v)
    {
        ImGui::Text("%lf", v);
    }
    
    void    text(float v)
    {
        ImGui::Text("%f", v);
    }
    
    void    text(int8_t v)
    {
        text((int) v);
    }

    void    text(int16_t v)
    {
        ImGui::Text("%hd", v);
    }
    
    void    text(int32_t v)
    {
        ImGui::Text("%d", v);
    }
    
    void    text(int64_t v)
    {
        ImGui::Text("%ld", v);
    }

    void    text(uint8_t v)
    {
        text((unsigned) v);
    }
    
    void    text(uint16_t v)
    {
        ImGui::Text("%hu", v);
    }
    
    void    text(uint32_t v)
    {
        ImGui::Text("%u", v);
    }
    
    void    text(uint64_t v)
    {
        ImGui::Text("%lu", v);
    }
    
    void    text(const char* z)
    {
        if(z)
            ImGui::TextUnformatted(z);
    }
    

    void    text(const std::string&v)
    {
        if(!v.empty())
            ImGui::TextUnformatted(v.data(), v.data()+v.size());
    }
    
    void    text(const std::filesystem::path& fp)
    {
        text(fp.string());
    }

    void    text(std::string_view v)
    {
        if(!v.empty())
            ImGui::TextUnformatted(v.data(), v.data()+v.size());
    }
    
    void    text(const Any& v)
    {
        text(v.printable());
    }
    
    void    text(const Quaternion3D& v)
    {
        ImGui::Text("{%lf, %lf, %lf, %lf}", v.w, v.x, v.y, v.z);
    }
    
    void    text(const Quaternion3F& v)
    {
        ImGui::Text("{%f, %f, %f, %f}", v.w, v.x, v.y, v.z);
    }
    
    void    text(const Rectangle2D& v)
    {
        ImGui::Text("{%lf × %lf @ (%+lf, %+lf)}", v.size.x, v.size.y, v.position.x, v.position.y );
    }
    
    void    text(const Rectangle2F& v)
    {
        ImGui::Text("{%f × %f @ (%+f, %+f)}", v.size.x, v.size.y, v.position.x, v.position.y );
    }
    
    void    text(const RGB3F&v)
    {
        ImGui::Text("(%f,%f,%f)", v.red, v.green, v.blue);
    }
    
    void    text(const RGB3U8&v)
    {
        ImGui::Text("(%i,%i,%i)", (int) v.red, (int) v.green, (int) v.blue);
    }
    
    void    text(const RGBA4F&v)
    {
        ImGui::Text("(%f,%f,%f,%f)", v.red, v.green, v.blue, v.alpha);
    }
    
    void    text(const RGBA4U8&v)
    {
        ImGui::Text("(%i,%i,%i,%i)", (int) v.red, (int) v.green, (int) v.blue, (int) v.alpha);
    }

    void    text(const Size2D& v)
    {
        ImGui::Text("{%lf × %lf}", v.x, v.y );
    }
    
    void    text(const Size2F& v)
    {
        ImGui::Text("{%f × %f}", v.x, v.y );
    }
    
    void    text(const Size2I& v)
    {
        ImGui::Text("{%i × %i}", v.x, v.y );
    }
    
    void    text(const Size2U& v)
    {
        ImGui::Text("{%u × %u}", v.x, v.y );
    }

    void    text(const Size3D& v)
    {
        ImGui::Text("{%lf × %lf × %lf}", v.x, v.y, v.z );
    }
    
    void    text(const Size3F& v)
    {
        ImGui::Text("{%f × %f × %f}", v.x, v.y, v.z );
    }
    
    void    text(const Size3I& v)
    {
        ImGui::Text("{%i × %i × %i}", v.x, v.y, v.z );
    }

    void    text(const Size3U& v)
    {
        ImGui::Text("{%u × %u × %u}", v.x, v.y, v.z );
    }
    
    void    text(const Size4D& v)
    {
        ImGui::Text("{%lf × %lf × %lf × %lf}", v.x, v.y, v.z, v.w );
    }
    
    void    text(const Size4F& v)
    {
        ImGui::Text("{%f × %f × %f × %f}", v.x, v.y, v.z, v.w );
    }
    
    void    text(const Size4I& v)
    {
        ImGui::Text("{%i × %i × %i × %i}", v.x, v.y, v.z, v.w );
    }

    void    text(const Size4U& v)
    {
        ImGui::Text("{%u × %u × %u × %u}", v.x, v.y, v.z, v.w );
    }
    
    void    text(const Tensor44D& v)
    {
        if(ImGui::BeginTable("Tensor44D", 4, ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_SizingFixedSame)){
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.xx);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.xy);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.xz);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.xw);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.yx);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.yy);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.yz);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.yw);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.zx);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.zy);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.zz);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.zw);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.wx);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.wy);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.wz);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v.ww);
            ImGui::EndTable();
        }
    }

    void    text(const Url& v)
    {
        text(to_string(v));
    }
    
    void    text(const UrlView& v)
    {
        text(to_string(v));
    }
    
    void    text(const UV2D& v)
    {
        ImGui::Text("{l%f, %lf}", v.u, v.v );
    }
    
    void    text(const UV2F& v)
    {
        ImGui::Text("{%f, %f}", v.u, v.v );
    }
    
    void    text(const UVW3D& v)
    {
        ImGui::Text("{%lf, %lf, %lf}", v.u, v.v, v.w );
    }
    
    void    text(const UVW3F& v)
    {
        ImGui::Text("{%f, %f, %f}", v.u, v.v, v.w );
    }
    
    void    text(const Vector1D& v)
    {
        ImGui::Text("{%lf}", v.x );
    }
    
    void    text(const Vector1F& v)
    {
        ImGui::Text("{%f}", v.x );
    }
    
    void    text(const Vector1U& v)
    {
        ImGui::Text("{%u}", v.x );
    }
    
    void    text(const Vector2D& v)
    {
        ImGui::Text("{%lf, %lf}", v.x, v.y );
    }
    
    void    text(const Vector2F& v)
    {
        ImGui::Text("{%f, %f}", v.x, v.y );
    }
    
    void    text(const Vector2U& v)
    {
        ImGui::Text("{%u, %u}", v.x, v.y );
    }
    
    void    text(const Vector3D& v)
    {
        ImGui::Text("{%lf, %lf, %lf}", v.x, v.y, v.z );
    }
    
    void    text(const Vector3F& v)
    {
        ImGui::Text("{%f, %f, %f}", v.x, v.y, v.z );
    }
    
    void    text(const Vector3U& v)
    {
        ImGui::Text("{%u, %u, %u}", v.x, v.y, v.z );
    }
    
    void    text(const Vector4D& v)
    {
        ImGui::Text("{%lf, %lf, %lf, %lf}", v.x, v.y, v.z, v.w );
    }
    
    void    text(const Vector4F& v)
    {
        ImGui::Text("{%f, %f, %f, %f}", v.x, v.y, v.z, v.w );
    }
    
    void    text(const Vector4U& v)
    {
        ImGui::Text("{%u, %u, %u, %u}", v.x, v.y, v.z, v.w );
    }

    void    text(const glm::mat4& v)
    {
        if(ImGui::BeginTable("glm::mat4", 4, ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_SizingFixedSame)){
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[0][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[0][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[0][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[0][3]);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[1][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[1][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[1][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[1][3]);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[2][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[2][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[2][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[2][3]);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[3][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[3][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[3][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%f", v[3][3]);
            ImGui::EndTable();
        }
    }
    
    void    text(const glm::dmat4& v)
    {
        if(ImGui::BeginTable("glm::dmat4", 4, ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_SizingFixedSame)){
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[0][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[0][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[0][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[0][3]);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[1][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[1][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[1][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[1][3]);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[2][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[2][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[2][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[2][3]);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[3][0]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[3][1]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[3][2]);
            if(ImGui::TableNextColumn())
                ImGui::Text("%lf", v[3][3]);
            ImGui::EndTable();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PipelineUtils.hpp"
#include <math/glm_types.hpp>
#include <math/color/RGBA.hpp>
#include <math/vector/Vector1.hpp>
#include <math/vector/Vector2.hpp>
#include <math/vector/Vector3.hpp>
#include <math/vector/Vector4.hpp>
#include <unordered_map>
#include <basic/meta/TypeInfo.hpp>


namespace yq {
    namespace engine {
        namespace {
            
            template <typename T>
            DataFormatData                dfd(tachyon::DataFormat df, unsigned int bindings=0, tachyon::IndexType it=IndexType())
            {
                if(!bindings)
                    bindings    = min_binding<T>();
                return DataFormatData{ meta<T>().id(), bindings, df, it };
            }
        
            auto    make_data_map()
            {
                std::unordered_map<unsigned int, tachyon::DataFormat>    ret;
                for(const DataFormatData& d : data_format_data())
                    ret[d.type_id]  = d.format;
                return ret;
            }

            auto    make_binding_map()
            {
                std::unordered_map<unsigned int, unsigned int>  ret;
                for(const DataFormatData& d : data_format_data())
                    ret[d.type_id]  = d.bindings;
                return ret;
            }
            
            auto    make_index_type_map()
            {
                std::unordered_map<unsigned int, IndexType>     ret;
                for(const DataFormatData& d : data_format_data())
                    ret[d.type_id]  = d.index;
                return ret;
            }
        }

        std::span<const DataFormatData>    data_format_data()
        {
            static const DataFormatData sList[] = {
                dfd<RGB3D>(tachyon::DataFormat::R64G64B64_SFLOAT, 2),
                dfd<RGB3F>(tachyon::DataFormat::R32G32B32_SFLOAT, 1),
                dfd<RGB3U8>(tachyon::DataFormat::R8G8B8_UNORM, 1),
                dfd<RGB3U16>(tachyon::DataFormat::R16G16B16_UNORM, 1),
                dfd<RGBA4D>(tachyon::DataFormat::R64G64B64A64_SFLOAT, 2),
                dfd<RGBA4F>(tachyon::DataFormat::R32G32B32A32_SFLOAT, 1),
                dfd<RGBA4U8>(tachyon::DataFormat::R8G8B8A8_UNORM, 1),
                dfd<RGBA4U16>(tachyon::DataFormat::R16G16B16A16_UNORM, 1),
                dfd<Vector1D>(tachyon::DataFormat::R64_SFLOAT, 1),
                dfd<Vector1F>(tachyon::DataFormat::R32_SFLOAT, 1),
                dfd<Vector1I>(tachyon::DataFormat::R32_SINT, 1),
                dfd<Vector1U>(tachyon::DataFormat::R32_UINT, 1),
                dfd<Vector2D>(tachyon::DataFormat::R64G64_SFLOAT, 1),
                dfd<Vector2F>(tachyon::DataFormat::R32G32_SFLOAT, 1),
                dfd<Vector2I>(tachyon::DataFormat::R32G32_SINT, 1),
                dfd<Vector2U>(tachyon::DataFormat::R32G32_UINT, 1),
                dfd<Vector3D>(tachyon::DataFormat::R64G64B64_SFLOAT, 2),
                dfd<Vector3F>(tachyon::DataFormat::R32G32B32_SFLOAT, 1),
                dfd<Vector3I>(tachyon::DataFormat::R32G32B32_SINT, 1),
                dfd<Vector3U>(tachyon::DataFormat::R32G32B32_UINT, 1),
                dfd<Vector4D>(tachyon::DataFormat::R64G64B64A64_SFLOAT, 2),
                dfd<Vector4F>(tachyon::DataFormat::R32G32B32A32_SFLOAT, 1),
                dfd<Vector4I>(tachyon::DataFormat::R32G32B32A32_SINT, 1),
                dfd<Vector4U>(tachyon::DataFormat::R32G32B32A32_UINT, 1),
                dfd<glm::vec1>(tachyon::DataFormat::R32_SFLOAT, 1),
                dfd<glm::dvec1>(tachyon::DataFormat::R64_SFLOAT, 1),
                dfd<glm::vec2>(tachyon::DataFormat::R32G32_SFLOAT, 1),
                dfd<glm::dvec2>(tachyon::DataFormat::R64G64_SFLOAT, 1),
                dfd<glm::vec3>(tachyon::DataFormat::R32G32B32_SFLOAT, 1),
                dfd<glm::dvec3>(tachyon::DataFormat::R64G64B64_SFLOAT, 2),
                dfd<glm::vec4>(tachyon::DataFormat::R32G32B32A32_SFLOAT, 1),
                dfd<glm::dvec4>(tachyon::DataFormat::R64G64B64A64_SFLOAT, 2),
                dfd<uint8_t>(tachyon::DataFormat::R8_UINT, 1, tachyon::IndexType::uint8),
                dfd<uint16_t>(tachyon::DataFormat::R16_UINT, 1, tachyon::IndexType::uint16),
                dfd<uint32_t>(tachyon::DataFormat::R32_UINT, 1, tachyon::IndexType::uint32)
            };
            
            return std::span<const DataFormatData>(std::begin(sList), std::end(sList));
        }

        unsigned int    data_binding(const TypeInfo& ti)
        {
            static auto the_map     = make_binding_map();
            auto    i  = the_map.find(ti.id());
            if(i != the_map.end())
                return i->second;
            return 0;
        }

        tachyon::DataFormat      data_format(const TypeInfo& ti)
        {
            static auto the_map     = make_data_map();
            auto    i  = the_map.find(ti.id());
            if(i != the_map.end())
                return i->second;
            return tachyon::DataFormat::UNDEFINED;
        }

        unsigned int    min_binding(size_t cb)
        {
            return (unsigned int)((cb + sizeof(Vector2D) - 1) / sizeof(Vector2D));
        }

        tachyon::IndexType       index_type(const TypeInfo&ti)
        {
            static auto the_map     = make_index_type_map();
            auto    i  = the_map.find(ti.id());
            if(i != the_map.end())
                return i->second;
            return tachyon::IndexType::none;
        }
    }
}

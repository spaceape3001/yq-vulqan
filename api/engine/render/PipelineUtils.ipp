////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PipelineUtils.hpp"
#include <math/glm_types.hpp>
#include <math/RGBA.hpp>
#include <math/Vector1.hpp>
#include <math/Vector2.hpp>
#include <math/Vector3.hpp>
#include <math/Vector4.hpp>
#include <unordered_map>
#include <basic/meta/TypeInfo.hpp>


namespace yq {
    namespace engine {
        namespace {
            
            template <typename T>
            DataFormatData                dfd(DataFormat df, unsigned int bindings=0, IndexType it=IndexType())
            {
                if(!bindings)
                    bindings    = min_binding<T>();
                return DataFormatData{ meta<T>().id(), bindings, df, it };
            }
        
            auto    make_data_map()
            {
                std::unordered_map<unsigned int, DataFormat>    ret;
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
                dfd<RGB3D>(DataFormat::R64G64B64_SFLOAT, 2),
                dfd<RGB3F>(DataFormat::R32G32B32_SFLOAT, 1),
                dfd<RGB3U8>(DataFormat::R8G8B8_UNORM, 1),
                dfd<RGB3U16>(DataFormat::R16G16B16_UNORM, 1),
                dfd<RGBA4D>(DataFormat::R64G64B64A64_SFLOAT, 2),
                dfd<RGBA4F>(DataFormat::R32G32B32A32_SFLOAT, 1),
                dfd<RGBA4U8>(DataFormat::R8G8B8A8_UNORM, 1),
                dfd<RGBA4U16>(DataFormat::R16G16B16A16_UNORM, 1),
                dfd<Vector1D>(DataFormat::R64_SFLOAT, 1),
                dfd<Vector1F>(DataFormat::R32_SFLOAT, 1),
                dfd<Vector1I>(DataFormat::R32_SINT, 1),
                dfd<Vector1U>(DataFormat::R32_UINT, 1),
                dfd<Vector2D>(DataFormat::R64G64_SFLOAT, 1),
                dfd<Vector2F>(DataFormat::R32G32_SFLOAT, 1),
                dfd<Vector2I>(DataFormat::R32G32_SINT, 1),
                dfd<Vector2U>(DataFormat::R32G32_UINT, 1),
                dfd<Vector3D>(DataFormat::R64G64B64_SFLOAT, 2),
                dfd<Vector3F>(DataFormat::R32G32B32_SFLOAT, 1),
                dfd<Vector3I>(DataFormat::R32G32B32_SINT, 1),
                dfd<Vector3U>(DataFormat::R32G32B32_UINT, 1),
                dfd<Vector4D>(DataFormat::R64G64B64A64_SFLOAT, 2),
                dfd<Vector4F>(DataFormat::R32G32B32A32_SFLOAT, 1),
                dfd<Vector4I>(DataFormat::R32G32B32A32_SINT, 1),
                dfd<Vector4U>(DataFormat::R32G32B32A32_UINT, 1),
                dfd<glm::vec1>(DataFormat::R32_SFLOAT, 1),
                dfd<glm::dvec1>(DataFormat::R64_SFLOAT, 1),
                dfd<glm::vec2>(DataFormat::R32G32_SFLOAT, 1),
                dfd<glm::dvec2>(DataFormat::R64G64_SFLOAT, 1),
                dfd<glm::vec3>(DataFormat::R32G32B32_SFLOAT, 1),
                dfd<glm::dvec3>(DataFormat::R64G64B64_SFLOAT, 2),
                dfd<glm::vec4>(DataFormat::R32G32B32A32_SFLOAT, 1),
                dfd<glm::dvec4>(DataFormat::R64G64B64A64_SFLOAT, 2),
                dfd<uint8_t>(DataFormat::R8_UINT, 1, IndexType::uint8),
                dfd<uint16_t>(DataFormat::R16_UINT, 1, IndexType::uint16),
                dfd<uint32_t>(DataFormat::R32_UINT, 1, IndexType::uint32)
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

        DataFormat      data_format(const TypeInfo& ti)
        {
            static auto the_map     = make_data_map();
            auto    i  = the_map.find(ti.id());
            if(i != the_map.end())
                return i->second;
            return DataFormat::UNDEFINED;
        }

        unsigned int    min_binding(size_t cb)
        {
            return (unsigned int)((cb + sizeof(Vector2D) - 1) / sizeof(Vector2D));
        }

        IndexType       index_type(const TypeInfo&ti)
        {
            static auto the_map     = make_index_type_map();
            auto    i  = the_map.find(ti.id());
            if(i != the_map.end())
                return i->second;
            return IndexType::none;
        }
    }
}

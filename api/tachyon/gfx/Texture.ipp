////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/gfx/Texture.hpp>
#include <tachyon/AssetFactory.hpp>
#include <tachyon/AssetInfoWriter.hpp>
#include <tachyon/Buffer.hpp>

namespace yq::tachyon {
    TypedAssetFactory<Texture>&  Texture::cache()
    {
        static TypedAssetFactory<Texture>   s_ret;
        return s_ret;
    }

    const Texture*       Texture::load(std::string_view pp)
    {
        return cache().load(pp);
    }

    ////////////////////////////////////////////////////////////////////////////////

    Texture::Texture()
    {
    }
    
    Texture::Texture(const ImageInfo& ii, Memory&& mem) : m_info(ii), m_memory(std::move(mem))
    {
    }

    size_t      Texture::data_size() const  
    {
        return m_memory.size();
    }

    Texture::~Texture()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    namespace {
        void    reg_texture()
        {
            auto ti = writer<Texture>();
            ti.description("Texture Asset");
        }

        YQ_INVOKE(reg_texture();)
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Texture)


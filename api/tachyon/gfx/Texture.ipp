////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/gfx/Texture.hpp>
#include <tachyon/core/AssetFactory.hpp>
#include <tachyon/core/AssetInfoWriter.hpp>
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

    Texture::Texture(const ImageInfo& ii, Memory&& mem) : info(ii), memory(std::move(mem))
    {
    }

    size_t      Texture::data_size() const  
    {
        return memory.size();
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


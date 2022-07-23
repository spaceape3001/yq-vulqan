////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <basic/DelayInit.hpp>
#include <engine/AssetCache.hpp>
#include <engine/Texture.hpp>

namespace yq {
    namespace engine {
        class TextureCache : public AssetCache {
            YQ_OBJECT_DECLARE(TextureCache, AssetCache)
        public:
        
        private:
            TextureCache();
            ~TextureCache();
        };


        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        TextureInfo::TextureInfo(std::string_view zName, const AssetInfo& base, const std::source_location& sl) :
            AssetInfo(zName, base, sl)
        {
            set_option(TEXTURE);
        }

        Texture::Texture()
        {
        }
        
        Texture::~Texture()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        TextureCache::TextureCache() : AssetCache(meta<TextureCache>())
        {
        }
        
        TextureCache::~TextureCache()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        TextureLoaderInfo::TextureLoaderInfo(std::string_view zName, const AssetLoaderInfo& base, const std::source_location& sl) :
            AssetLoaderInfo(zName, base, sl)
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////
        
        YQ_INVOKE(
            auto ti = writer<Texture>();
            ti.description("Texture Asset");
            
            auto tc = writer<TextureCache>();
            tc.asset<Texture>();
            tc.loader<TextureLoader>();
            tc.description("Texture Cache object");
            
            auto tl = writer<TextureLoader>();
            tl.description("Texture Loader");
        )
    }

}

YQ_OBJECT_IMPLEMENT(yq::engine::Texture)
YQ_OBJECT_IMPLEMENT(yq::engine::TextureCache)
YQ_OBJECT_IMPLEMENT(yq::engine::TextureLoader)


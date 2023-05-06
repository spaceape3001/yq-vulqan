////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/AssetFactory.hpp>
#include <tachyon/gfx/Texture.hpp>

#include <basic/DelayInit.hpp>
#include <basic/ErrorDB.hpp>

#include <stb_image.h>

namespace yq::tachyon::stb {
    using unable_to_load_image  = error_db::entry<"Unable to load the specified image">;
    
    namespace {
        void    reg_stbtexloader()
        {
            Texture::cache().add_loader(
                { "bmp", "gif", "jpg", "jpeg", "hdr", "png", "tga" },
                [](const std::filesystem::path&pth) -> Texture* 
                {
                    std::string     file    = pth.string();
                    ImageInfo       info;
                    int             w, h, c = 0;
                    void*           pixels  = stbi_load(pth.c_str(), &w, &h, &c, 4);
                    if(!pixels)
                        throw create_error<"Unable to load the specified image">();
                    info.size.x     = w;
                    info.size.y     = h;
                    size_t          imgsize = info.size.x * info.size.y * 4;
                        
                    return new Texture(info, Memory(pixels, imgsize, [](const void* data, size_t){
                        stbi_image_free((void*) data);
                    }));
                }
            );
        }
        
        YQ_INVOKE(reg_stbtexloader();)
    }

}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/image/Image.hpp>

#include <yq-toolbox/basic/DelayInit.hpp>
#include <yq-toolbox/basic/ErrorDB.hpp>

#include <stb_image.h>
#include <stb_image_write.h>

namespace yq::tachyon::stb {
    using unable_to_load_image  = error_db::entry<"Unable to load the specified image">;
    using image_size_mismatch   = error_db::entry<"Provided image size exceeds the bytes in the buffer.">;
    
    Image*   stb_loader(const std::filesystem::path&pth)
    {
        std::string     file    = pth.string();
        ImageInfo       info;
        int             w, h, c = 0;
        void*           pixels  = stbi_load(file.c_str(), &w, &h, &c, 4);
        if(!pixels)
            throw create_error<"Unable to load the specified image">();
        info.size.x     = w;
        info.size.y     = h;
        size_t          imgsize = info.size.x * info.size.y * 4;
            
        return new Image(info, Memory(SET, pixels, imgsize, 4, [](const void* data, size_t){
            stbi_image_free((void*) data);
        }));
    }
    
    std::error_code   stb_save_png(const Image& img, const std::filesystem::path& pth)
    {
        size_t  minSize = img.info.size.x * img.info.size.y * 4;
        if(img.memory.bytes() < minSize)
            return image_size_mismatch();
        int r = stbi_write_png(pth.c_str(), img.info.size.x, img.info.size.y, 5, img.memory.data(), 4);
        if(!r)
            return create_error<"Unable to export as png">();
        return {};
    }

    void    reg_stb_loader()
    {
        Image::cache().add_loader(
            { "bmp", "gif", "jpg", "jpeg", "hdr", "png", "tga" },
            stb_loader
        );
        Image::cache().add_saver(
            { "png" },
            stb_save_png
        );
    }
        
    YQ_INVOKE(reg_stb_loader();)
}

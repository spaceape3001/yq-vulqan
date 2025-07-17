////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/asset/Asset.hxx>
#include <tachyon/asset/Raster.hpp>

#include <yq/core/DelayInit.hpp>
#include <yq/core/ErrorDB.hpp>

#include <stb_image.h>
#include <stb_image_write.h>

namespace yq::tachyon::stb {
    using unable_to_load_image  = error_db::entry<"Unable to load the specified image">;
    using image_size_mismatch   = error_db::entry<"Provided image size exceeds the bytes in the buffer.">;
    
    Raster*   stb_loader(const std::filesystem::path&pth)
    {
        std::string     file    = pth.string();
        RasterInfo      info;
        int             w, h, c = 0;
        void*           pixels  = stbi_load(file.c_str(), &w, &h, &c, 4);
        if(!pixels)
            throw create_error<"Unable to load the specified image">();
        
        info.size.x     = w;
        info.size.y     = h;
        size_t          imgsize = info.size.x * info.size.y * 4;

        return new Raster(info, Memory(SET, pixels, imgsize, 4, [](const void* data, size_t){
            stbi_image_free((void*) data);
        }));
    }
    
    std::error_code   stb_save_bmp(const Raster& img, const std::filesystem::path& pth)
    {
        size_t  minSize = img.info.size.x * img.info.size.y * 4;
        if(img.memory.bytes() < minSize)
            return image_size_mismatch();
        int r = stbi_write_bmp(pth.c_str(), img.info.size.x, img.info.size.y, 4, img.memory.data());
        if(!r)
            return create_error<"Unable to export as bmp">();
        return {};
    }

    std::error_code   stb_save_jpg(const Raster& img, const std::filesystem::path& pth)
    {
        size_t  minSize = img.info.size.x * img.info.size.y * 4;
        if(img.memory.bytes() < minSize)
            return image_size_mismatch();
        int r = stbi_write_jpg(pth.c_str(), img.info.size.x, img.info.size.y, 4, img.memory.data(), 90);
        if(!r)
            return create_error<"Unable to export as jpg">();
        return {};
    }

    std::error_code   stb_save_png(const Raster& img, const std::filesystem::path& pth)
    {
        #if 0
        uint8_t comp        = 0;
        size_t  stride      = 0;
        size_t  bpp         = 0;
        
        //  Eventually get smart, assume RGBA u8 for now....
        
        switch(img.info.format){
        }
        #endif
    
        size_t  minSize = img.info.size.x * img.info.size.y * 4;
        if(img.memory.bytes() < minSize)
            return image_size_mismatch();
        int r = stbi_write_png(pth.c_str(), img.info.size.x, img.info.size.y, 4, img.memory.data(), 4 * img.info.size.x);
        if(!r)
            return create_error<"Unable to export as png">();
        return {};
    }

    void    reg_stb_loader()
    {
        Raster::IO::add_loader(
            {.extensions={ "bmp", "gif", "jpg", "jpeg", "hdr", "png", "tga" }},
            stb_loader
        );
        Raster::IO::add_saver(
            {.extensions={ "bmp" }},
            stb_save_bmp
        );
        Raster::IO::add_saver(
            {.extensions = { "jpg" }},
            stb_save_jpg
        );
        Raster::IO::add_saver(
            {.extensions ={ "png" }},
            stb_save_png
        );
    }
        
    YQ_INVOKE(reg_stb_loader();)
}

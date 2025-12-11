////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImageHMV.hpp"

#include <yq/core/DelayInit.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/resource/ResourceDriverAPI.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/text/format.hpp>
#include <yq/text/match.hpp>
#include <yq/text/parse.hpp>
#include <yq/text/split.hpp>
#include <yq/text/transform.hpp>
#include <yq/text/vsplit.hpp>

#include <yq/resource/Resource.hxx>
#include <yq/shape/Size4.hxx>
#include <fstream>
#include <functional>

namespace yq::errors {
    using unsupported_data_format   = error_db::entry<"Unsupported data format">;
    using insufficient_bytes        = error_db::entry<"Insufficient bytes for the claimed size">;
}

namespace yq::tachyon {
    RasterPtr       loadHMV(const std::filesystem::path&fpath)
    {
        std::ifstream   fin(fpath);
        if(!fin.good())
            return {};
        return loadHMV(fin, to_url(fpath));
    }
    
    struct HMVExtractor {
        virtual bool        add(std::string_view) = 0;
        virtual Memory      commit() = 0;
        virtual uint8_t     multiplier() const = 0;
        virtual size_t      size() const = 0;
    };
    
    namespace {
        template <typename T>
        struct Extract : public HMVExtractor {
            std::vector<T>  data;
            uint8_t         N;
            
            static Expect<T>    parse(std::string_view);
            
            Extract(uint8_t n=1) : N(n) {}
            
            bool        add(std::string_view text)
            {
                size_t  cnt = 0;
                if(vsplit(text, ',', [&](std::string_view v){
                    auto x = parse(trimmed(v));
                    if(!x)
                        return true;
                    data.push_back(*x);
                    ++cnt;
                    return false;
                }))
                    return true;
                
                for(;cnt < N; ++cnt)
                    data.push_back(T{});
                return false;
            }

            Memory      commit() override
            {
                return Memory(COPY, data);
            }
            

            uint8_t     multiplier() const override 
            { 
                return N; 
            }
            size_t      size() const override { return data.size(); }

        };
        
        template <> 
        double_x Extract<double>::parse(std::string_view v)
        {
            return to_double(v);
        }

        template <> 
        float_x Extract<float>::parse(std::string_view v)
        {
            return to_float(v);
        }

        template <> 
        int8_x Extract<int8_t>::parse(std::string_view v)
        {
            return to_int8(v);
        }

        template <> 
        int16_x Extract<int16_t>::parse(std::string_view v)
        {
            return to_int16(v);
        }

        template <> 
        int32_x Extract<int32_t>::parse(std::string_view v)
        {
            return to_int32(v);
        }

        template <> 
        int64_x Extract<int64_t>::parse(std::string_view v)
        {
            return to_int64(v);
        }

        template <> 
        uint8_x Extract<uint8_t>::parse(std::string_view v)
        {
            return to_uint8(v);
        }

        template <> 
        uint16_x Extract<uint16_t>::parse(std::string_view v)
        {
            return to_uint16(v);
        }

        template <> 
        uint32_x Extract<uint32_t>::parse(std::string_view v)
        {
            return to_uint32(v);
        }

        template <> 
        uint64_x Extract<uint64_t>::parse(std::string_view v)
        {
            return to_uint64(v);
        }
    }
    
    
    RasterPtr       loadHMV(std::istream&istr, const Url& url)
    {
        static constexpr const size_t   kBufferSize = 131072;
        char                                    buffer[kBufferSize];
        bool                                    extractMode = false;
        RasterInfo                              info;
        
        //! Expected count of values
        size_t                                  count       = 0;
        std::unique_ptr<HMVExtractor>           extractor;
        
        memset(buffer, 0, kBufferSize);

        while(!istr.eof()){
            buffer[0] = '\0';   // safety
            
            istr.getline(buffer, kBufferSize);
            
            if(!buffer[0]){
                if(!extractor){
                    tachyonError << "Loading " << url << ": No valid format specified.";
                    return {};
                }
                if(!count){
                    tachyonError << "Loading " << url << ": No size ever specified.";
                    return {};
                }
                extractMode = true;
                continue;
            }
            
            if(extractMode){
                if(vsplit(buffer, ';', [&](std::string_view v){
                    if(v.empty())
                        return false;
                    return extractor->add(v);
                })){
                    tachyonError << "Loading " << url << ": Bad data.";
                    return {};
                }
            } else {
                const char* eq  = strchr(buffer, '=');
                if(!eq){
                    tachyonError << "Loading " << url << ": Bad key/value line.";
                    return {};
                }
                
                std::string_view k = trimmed(std::string_view(buffer, eq-buffer));
                std::string_view v = trimmed(std::string_view(eq+1));
                if(is_similar(k, "array")){
                    auto x  = to_unsigned(v);
                    if(!x){
                        tachyonError << "Loading " << url << ": Bad array layers value";
                        return {};
                    }
                    info.arrayLayers    = *x;
                } 
                if(is_similar(k, "format")){
                    bool    ok  = false;
                    info.format = DataFormat(v, &ok);
                    if(!ok){
                        tachyonError << "Loading " << url << ": Bad format";
                        return {};
                    }
                    
                    switch(info.format){
                    case DataFormat::R8_SINT:
                        extractor   = std::make_unique<Extract<int8_t>>();
                        break;
                    case DataFormat::R8_UINT:
                        extractor   = std::make_unique<Extract<uint8_t>>();
                        break;
                    case DataFormat::R8G8_SINT:
                        extractor   = std::make_unique<Extract<int8_t>>(2);
                        break;
                    case DataFormat::R8G8_UINT:
                        extractor   = std::make_unique<Extract<uint8_t>>(2);
                        break;
                    case DataFormat::R8G8B8_SINT:
                        extractor   = std::make_unique<Extract<int8_t>>(3);
                        break;
                    case DataFormat::R8G8B8_UINT:
                        extractor   = std::make_unique<Extract<uint8_t>>(3);
                        break;
                    case DataFormat::R8G8B8A8_SINT:
                        extractor   = std::make_unique<Extract<int8_t>>(4);
                        break;
                    case DataFormat::R8G8B8A8_UINT:
                        extractor   = std::make_unique<Extract<uint8_t>>(4);
                        break;
                    case DataFormat::R16_SINT:
                        extractor   = std::make_unique<Extract<int16_t>>();
                        break;
                    case DataFormat::R16_UINT:
                        extractor   = std::make_unique<Extract<uint16_t>>();
                        break;
                    case DataFormat::R16G16_SINT:
                        extractor   = std::make_unique<Extract<int16_t>>(2);
                        break;
                    case DataFormat::R16G16_UINT:
                        extractor   = std::make_unique<Extract<uint16_t>>(2);
                        break;
                    case DataFormat::R16G16B16_SINT:
                        extractor   = std::make_unique<Extract<int16_t>>(3);
                        break;
                    case DataFormat::R16G16B16_UINT:
                        extractor   = std::make_unique<Extract<uint16_t>>(3);
                        break;
                    case DataFormat::R16G16B16A16_SINT:
                        extractor   = std::make_unique<Extract<int16_t>>(4);
                        break;
                    case DataFormat::R16G16B16A16_UINT:
                        extractor   = std::make_unique<Extract<uint16_t>>(4);
                        break;
                    case DataFormat::R32_SFLOAT:
                        extractor   = std::make_unique<Extract<float>>();
                        break;
                    case DataFormat::R32_SINT:
                        extractor   = std::make_unique<Extract<int32_t>>();
                        break;
                    case DataFormat::R32_UINT:
                        extractor   = std::make_unique<Extract<uint32_t>>();
                        break;
                    case DataFormat::R32G32_SFLOAT:
                        extractor   = std::make_unique<Extract<float>>(2);
                        break;
                    case DataFormat::R32G32_SINT:
                        extractor   = std::make_unique<Extract<int32_t>>(2);
                        break;
                    case DataFormat::R32G32_UINT:
                        extractor   = std::make_unique<Extract<uint32_t>>(2);
                        break;
                    case DataFormat::R32G32B32_SFLOAT:
                        extractor   = std::make_unique<Extract<float>>(3);
                        break;
                    case DataFormat::R32G32B32A32_SFLOAT:
                        extractor   = std::make_unique<Extract<float>>(4);
                        break;
                    case DataFormat::R64_SFLOAT:
                        extractor   = std::make_unique<Extract<double>>();
                        break;
                    case DataFormat::R64_SINT:
                        extractor   = std::make_unique<Extract<int64_t>>();
                        break;
                    case DataFormat::R64_UINT:
                        extractor   = std::make_unique<Extract<uint64_t>>();
                        break;
                    case DataFormat::R64G64_SFLOAT:
                        extractor   = std::make_unique<Extract<double>>(2);
                        break;
                    case DataFormat::R64G64B64_SFLOAT:
                        extractor   = std::make_unique<Extract<double>>(3);
                        break;
                    case DataFormat::R64G64B64A64_SFLOAT:
                        extractor   = std::make_unique<Extract<double>>(4);
                        break;
                    default:
                        tachyonError << "Loading " << url << ": unsupported format";
                        return {};
                    }
                } 
                if(is_similar(k, "mip")){
                    auto x  = to_unsigned(v);
                    if(!x){
                        tachyonError << "Loading " << url << ": Bad array layers value";
                        return {};
                    }
                    info.mipLevels = *x;
                } 
                if(is_similar(k, "size")){
                    auto        bits   = split(v, ',');
                    std::vector<unsigned>   sizes;
                    count   = 1;
                    
                    for(auto& b : split(v, ',')){
                        auto x = to_unsigned(b);
                        if(!x || !*x){
                            tachyonError << "Loading " << url << ": invalid size specification";
                            return {};
                        }
                        sizes.push_back(*x);
                        count *= *x;
                    }
                    
                    switch(sizes.size()){
                    case 4:
                        info.size.w     = sizes[3];
                        [[fallthrough]];
                    case 3:
                        info.size.z     = sizes[2];
                        [[fallthrough]];
                    case 2:
                        info.size.y     = sizes[1];
                        [[fallthrough]];
                    case 1:
                        info.size.x     = sizes[0];
                        break;
                    case 0:
                    default:
                        tachyonError << "Loading " << url << ": invalid size specification";
                        return {};
                    }
                } 
                if(is_similar(k, "tiling")){
                    bool    ok  = false;
                    info.tiling = ImageTiling(v, &ok);
                    if(!ok){
                        tachyonError << "Loading " << url << ": Bad image tiling";
                        return {};
                    }
                } 
                if(is_similar(k, "type")){
                    bool    ok  = false;
                    info.type = RasterType(v, &ok);
                    if(!ok){
                        tachyonError << "Loading " << url << ": Bad image tiling";
                        return {};
                    }
                } 
            }
        }
        
        if(!extractor){
            tachyonError << "Loading " << url << ": Unsure what to load";
            return {};
        }
            
        if(extractor->size() < count * extractor->multiplier()){
            tachyonError << "Loading " << url << ": Insufficient values";
            return {};
        }
        
        Memory mem = extractor->commit();
        if(!mem){
            tachyonError << "Loading " << url << ": Unable to commit values to memory";
            return {};
        }
        
        return new Raster(info, std::move(mem));
    }
    
    std::error_code saveHMV(const Raster& ras, const std::filesystem::path& fpath)
    {
        std::ofstream   fout(fpath, std::ios_base::out | std::ios_base::trunc);
        if(!fout.good()){
            tachyonError << "Unable to open " << fpath << " for writing.";
            return errors::cant_open_write();
        }
        return saveHMV(ras, fout, to_url(fpath));
    }
    
    struct HMVWritor {
        virtual uint8_t multiplier() const = 0;
        virtual size_t  per_channel_byte() const = 0;
        virtual const void*    write(std::ostream& str, const void*, size_t count) const = 0;
    };
    namespace {
        template <typename T>
        struct Writor : public HMVWritor {
            uint8_t N;
            Writor(uint8_t n=1) : N(n) {}
            uint8_t multiplier() const override { return N; }
            size_t  per_channel_byte() const override { return sizeof(T); }
            const void* write(std::ostream& str, const void* buffer, size_t count) const  override
            {
                const T* data = (const T*) buffer;
                for(size_t i=0; i<count; ++i){
                    if(i)
                        str << "; ";
                    for(uint8_t n=0;n<N;++n){
                        if(n)
                            str << ',';
                        str << to_string_view(data[i*N+n]);
                    }
                }
                return data + count*N;
            }
        };
    }
    
    std::error_code saveHMV(const Raster&ras, std::ostream& ostr, const Url& url)
    {
        std::unique_ptr<HMVWritor>  writor;
        
        switch(ras.info.format){
        case DataFormat::R8_SINT:
            writor  = std::make_unique<Writor<int8_t>>();
            break;
        case DataFormat::R8_UINT:
            writor  = std::make_unique<Writor<uint8_t>>();
            break;
        case DataFormat::R8G8_SINT:
            writor  = std::make_unique<Writor<int8_t>>(2);
            break;
        case DataFormat::R8G8_UINT:
            writor  = std::make_unique<Writor<uint8_t>>(2);
            break;
        case DataFormat::R8G8B8_SINT:
            writor  = std::make_unique<Writor<int8_t>>(3);
            break;
        case DataFormat::R8G8B8_UINT:
            writor  = std::make_unique<Writor<uint8_t>>(3);
            break;
        case DataFormat::R8G8B8A8_SINT:
            writor  = std::make_unique<Writor<int8_t>>(4);
            break;
        case DataFormat::R8G8B8A8_UINT:
            writor  = std::make_unique<Writor<uint8_t>>(4);
            break;
        case DataFormat::R16_SINT:
            writor  = std::make_unique<Writor<int16_t>>();
            break;
        case DataFormat::R16_UINT:
            writor  = std::make_unique<Writor<uint16_t>>();
            break;
        case DataFormat::R16G16_SINT:
            writor  = std::make_unique<Writor<int16_t>>(2);
            break;
        case DataFormat::R16G16_UINT:
            writor  = std::make_unique<Writor<uint16_t>>(2);
            break;
        case DataFormat::R16G16B16_SINT:
            writor  = std::make_unique<Writor<int16_t>>(3);
            break;
        case DataFormat::R16G16B16_UINT:
            writor  = std::make_unique<Writor<uint16_t>>(3);
            break;
        case DataFormat::R16G16B16A16_SINT:
            writor  = std::make_unique<Writor<int16_t>>(4);
            break;
        case DataFormat::R16G16B16A16_UINT:
            writor  = std::make_unique<Writor<uint16_t>>(4);
            break;
        case DataFormat::R32_SFLOAT:
            writor  = std::make_unique<Writor<float>>();
            break;
        case DataFormat::R32_SINT:
            writor  = std::make_unique<Writor<int32_t>>();
            break;
        case DataFormat::R32_UINT:
            writor  = std::make_unique<Writor<uint32_t>>();
            break;
        case DataFormat::R32G32_SFLOAT:
            writor  = std::make_unique<Writor<float>>(2);
            break;
        case DataFormat::R32G32_SINT:
            writor  = std::make_unique<Writor<int32_t>>(2);
            break;
        case DataFormat::R32G32_UINT:
            writor  = std::make_unique<Writor<uint32_t>>(2);
            break;
        case DataFormat::R32G32B32_SFLOAT:
            writor  = std::make_unique<Writor<float>>(3);
            break;
        case DataFormat::R32G32B32_SINT:
            writor  = std::make_unique<Writor<int32_t>>(3);
            break;
        case DataFormat::R32G32B32_UINT:
            writor  = std::make_unique<Writor<uint32_t>>(3);
            break;
        case DataFormat::R32G32B32A32_SFLOAT:
            writor  = std::make_unique<Writor<float>>(4);
            break;
        case DataFormat::R32G32B32A32_SINT:
            writor  = std::make_unique<Writor<int32_t>>(4);
            break;
        case DataFormat::R32G32B32A32_UINT:
            writor  = std::make_unique<Writor<uint32_t>>(4);
            break;
        case DataFormat::R64_SFLOAT:
            writor  = std::make_unique<Writor<double>>();
            break;
        case DataFormat::R64_SINT:
            writor  = std::make_unique<Writor<int64_t>>();
            break;
        case DataFormat::R64_UINT:
            writor  = std::make_unique<Writor<uint64_t>>();
            break;
        case DataFormat::R64G64_SFLOAT:
            writor  = std::make_unique<Writor<double>>(2);
            break;
        case DataFormat::R64G64_SINT:
            writor  = std::make_unique<Writor<int64_t>>(2);
            break;
        case DataFormat::R64G64_UINT:
            writor  = std::make_unique<Writor<uint64_t>>(2);
            break;
        case DataFormat::R64G64B64_SFLOAT:
            writor  = std::make_unique<Writor<double>>(3);
            break;
        case DataFormat::R64G64B64_SINT:
            writor  = std::make_unique<Writor<int64_t>>(3);
            break;
        case DataFormat::R64G64B64_UINT:
            writor  = std::make_unique<Writor<uint64_t>>(3);
            break;
        case DataFormat::R64G64B64A64_SFLOAT:
            writor  = std::make_unique<Writor<double>>(4);
            break;
        case DataFormat::R64G64B64A64_SINT:
            writor  = std::make_unique<Writor<int64_t>>(4);
            break;
        case DataFormat::R64G64B64A64_UINT:
            writor  = std::make_unique<Writor<uint64_t>>(4);
            break;
        default:
            break;
        }
        
        if(!writor)
            return errors::unsupported_data_format();
        
        
        size_t nx = std::max(1U, ras.info.size.x);
        size_t ny = std::max(1U, ras.info.size.y);
        size_t nz = std::max(1U, ras.info.size.z);
        size_t nw = std::max(1U, ras.info.size.w);
        
        size_t  size    = nx * ny * nz * nw * writor->per_channel_byte() * writor->multiplier();
        if(ras.memory.bytes() < size)
            return errors::insufficient_bytes();
        const void* data    = ras.memory.data();
        if(!data)
            return errors::null_pointer();


        ostr << "array=" << ras.info.arrayLayers << '\n';
        ostr << "format=" << ras.info.format.key() << '\n';
        ostr << "mip=" << ras.info.mipLevels << '\n';
        ostr << "size=" << ras.info.size.x << "," << ras.info.size.y << "," << ras.info.size.z << "," << ras.info.size.w << '\n';
        ostr << "tiling=" << ras.info.tiling.key() << '\n';
        ostr << "type=" << ras.info.type.key() << '\n';
        ostr << '\n';

        for(unsigned w = 0; w<nw; ++w)
            for(unsigned z = 0; z<nz; ++z)
                for(unsigned y = 0; y<ny; ++y)
        {
            data    = writor->write(ostr, data, nx);
            ostr << '\n';
        }
        return {};
    }
}

namespace {
    using namespace yq;
    using namespace yq::tachyon;

    RasterPtr   loadHMV_driver(std::istream& istr, const ResourceLoadAPI&api)
    {
        return loadHMV(istr, api.url());
    }

    std::error_code saveHMV_driver(const Raster& ras, std::ostream&ostr, const ResourceSaveAPI&api)
    {
        return saveHMV(ras, ostr, api.url());
    }

    void    reg_imageHMV()
    {
        Raster::IO::add_loader({.extensions={"hmv"}}, loadHMV_driver);
        Raster::IO::add_saver({.extensions={"hmv"}}, saveHMV_driver);
    }
    
    YQ_INVOKE(reg_imageHMV();)
}

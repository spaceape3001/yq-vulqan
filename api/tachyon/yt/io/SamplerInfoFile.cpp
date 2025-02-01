////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/io/SamplerInfoFile.hpp>

#include <yq/strings.hpp>
#include <yq/container/set_utils.hpp>
#include <yq/keyv/KeyValue.hpp>
#include <yq/text/join.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yt/strings.hpp>

namespace yq::tachyon {
    #if 0
    static const string_view_initializer_list_t szFlags                 = { "Flags", "Flag" };
    static const string_view_initializer_list_t szMagnitudeFilter       = { "MagnitudeFilter", "MagFilter" };
    static const string_view_initializer_list_t szMiniumFilter          = { "MinimumFilter", "MinFilter" };
    static const string_view_initializer_list_t szMipMapMode            = { "MipmapMode" };
    static const string_view_initializer_list_t szAddressMode           = { "AddressMode" };
    static const string_view_initializer_list_t szMipLODBias            = { "MipLODBias" };
    static const string_view_initializer_list_t szAnisotropyEnable      = { "AnistropyEnable", "Anistropy" };
    static const string_view_initializer_list_t szMaxAnistropy          = { "MaxAnistropy" };
    static const string_view_initializer_list_t szCompareEnable         = { "CompareEnable" };
    static const string_view_initializer_list_t szCompareOp             = { "Compare" };
    static const string_view_initializer_list_t szMinLOD                = { "MinLOD" };
    static const string_view_initializer_list_t szMaxLOD                = { "MaxLOD" };
    static const string_view_initializer_list_t szLOD                   = { "LOD" };
    static const string_view_initializer_list_t szBorder                = { "Border" };
    static const string_view_initializer_list_t szBorderColor           = { "BorderColor" };
    static const string_view_initializer_list_t szCustomBorder          = { "CustomBorder" };
    static const string_view_initializer_list_t szUnnormalizedCoords    = { "UnnormalizedCoordinates" };
    #endif

    SamplerInfo::File::File(SamplerInfo& info) : m_info(&info), m_const(false)
    {
    }
    
    SamplerInfo::File::File(const SamplerInfo& info) : m_info(const_cast<SamplerInfo*>(&info)), m_const(true)
    {
    }
    
    SamplerInfo::File::~File()
    {
    }
    
    std::error_code     SamplerInfo::File::read(KVTree&&attrs, std::string_view fname)    
    {
    #if 0
        SamplerInfo&  info = *m_info;
        info        = SamplerInfo();
        
        auto flags      = make_vector(attrs.values_set(kv::key({"flag", "flags"})));
        auto magFilter  = attrs.value(kv::key("magfilter"));
        auto minFilter  = attrs.value(
        
        
        info.flags          = SamplerCreateFlags(span(flagKeys));
        
        std::string_view    sfilt   = attrs.value("magfilter");
        if(!sfilt.empty()){
            info.magFilter  = SamplerFilter(sfilt);
        }
        sfilt               = attrs.value("minFilter");
        if(!sfilt.empty())
            info.minFilter  = SamplerFilter(sfilt);
    #endif
        return errors::todo();
    }
    
    std::error_code     SamplerInfo::File::write(KVTree&attrs) const
    {
    #if 0
        const SamplerInfo&  info = *m_info;
    #endif
        return errors::todo();
    }
    

    std::error_code     sampler_info_load(SamplerInfo&is, const std::filesystem::path& path)
    {
        SamplerInfo::File   file(is);
        return file.load(path);
    }

    std::error_code     sampler_info_save(const std::filesystem::path&path, const SamplerInfo&is)
    {
        SamplerInfo::File   file(is);
        return file.save_to(path);
    }
}

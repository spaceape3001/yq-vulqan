////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/asset/AssetInfoWriter.hpp>
#include <yq-vulqan/pixmap/Pixmap.hpp>

namespace yq::tachyon {

    template <class C>
    class PixmapInfo::Writer : public AssetInfo::Writer<C> {
    public:
        Writer(PixmapInfo* pixmapInfoPtr) : AssetInfo::Writer<C>(pixmapInfoPtr), m_meta(pixmapInfoPtr)
        {
        }
        
        Writer(PixmapInfo& pixmapInfoRef) : Writer(&pixmapInfoRef)
        {
        }
        
        void    data_format(DataFormat df)
        {
            if(m_meta){
                m_meta -> m_dataFormat  = df;
            }
        }
        
    private:
        PixmapInfo* m_meta;
    };
}

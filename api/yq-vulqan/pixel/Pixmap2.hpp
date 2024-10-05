////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/pixmap/Pixmap.hpp>

namespace yq::tachyon {
    template <typename> class TypedAssetFactory;
    struct AssetLoadOptions;

    class Pixmap2Info : public PixmapInfo {
    public:
        Pixmap2Info(std::string_view, const AssetInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class Pixmap2 : public Pixmap {
        YQ_OBJECT_INFO(Pixmap2Info)
        YQ_OBJECT_DECLARE(Pixmap2, Pixmap)
    public:

        //! Cache of images
        static TypedAssetFactory<Pixmap2>&      cache();

        uint8_t                                 dimension_count() const { return 2; }
        
        static Pixmap2CPtr                      load(std::string_view);
        static Pixmap2CPtr                      load(std::string_view, const AssetLoadOptions&);
        
    protected:
        Coord2<index_t>         m_size;
        Coord2<EdgeAction>      m_negative{ AxisAction::Error, AxisAction::Error};
        Coord2<EdgeAction>      m_positive{ AxisAction::Error, AxisAction::Error};
    };
}


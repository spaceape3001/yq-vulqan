////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/XTachyon.hpp>
#include <QObject>

namespace yq::tachyon {
    class YTachyon : public XTachyon<QObject,Tachyon> {
        YQ_TACHYON_DECLARE(YTachyon, Tachyon)
        Q_OBJECT
    public:
    
    
        // PUSH HERE...

        YTachyon();
        ~YTachyon();
    
        static void init_meta();
    };
}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/DelayInit.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <QMetaType>

Q_DECLARE_METATYPE(yq::tachyon::TachyonID)

namespace yq::tachyon {
    YQ_INVOKE( qRegisterMetaType<TachyonID>(); )
}

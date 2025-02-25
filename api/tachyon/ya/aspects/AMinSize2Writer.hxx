////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMinSize2.hpp>
#include <ya/commands/size/AddMinSize2.hpp>
#include <ya/commands/size/AddMinSizeX.hpp>
#include <ya/commands/size/AddMinSizeY.hpp>
#include <ya/commands/size/MultiplyMinSize.hpp>
#include <ya/commands/size/MultiplyMinSize2.hpp>
#include <ya/commands/size/MultiplyMinSizeX.hpp>
#include <ya/commands/size/MultiplyMinSizeY.hpp>
#include <ya/commands/size/SetMinSize2.hpp>
#include <ya/commands/size/SetMinSizeX.hpp>
#include <ya/commands/size/SetMinSizeY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize²>();
        w.property(UNSAFE, "min_size", &AMinSize²::m_min_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMinSize²::on_set_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_set_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_set_min_sizeY);

        w.slot(UNSAFE, &AMinSize²::on_add_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_add_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_add_min_sizeY);
        
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_sizeY);
    }
}

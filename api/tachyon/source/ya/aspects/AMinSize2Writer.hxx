////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMinSize2.hpp>
#include <ya/commands/spatial/AddMinSize2.hpp>
#include <ya/commands/spatial/AddMinSizeX.hpp>
#include <ya/commands/spatial/AddMinSizeY.hpp>
#include <ya/commands/spatial/MultiplyMinSize.hpp>
#include <ya/commands/spatial/MultiplyMinSize2.hpp>
#include <ya/commands/spatial/MultiplyMinSizeX.hpp>
#include <ya/commands/spatial/MultiplyMinSizeY.hpp>
#include <ya/commands/spatial/SetMinSize2.hpp>
#include <ya/commands/spatial/SetMinSizeX.hpp>
#include <ya/commands/spatial/SetMinSizeY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize²>();
        w.property(UNSAFE, "min_size", &AMinSize²::m_min_size);

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

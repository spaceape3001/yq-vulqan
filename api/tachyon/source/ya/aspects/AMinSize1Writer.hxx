////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AMinSize1.hpp>
#include <ya/commands/spatial/AddMinSize1.hpp>
#include <ya/commands/spatial/AddMinSizeX.hpp>
#include <ya/commands/spatial/MultiplyMinSize.hpp>
#include <ya/commands/spatial/MultiplyMinSize1.hpp>
#include <ya/commands/spatial/MultiplyMinSizeX.hpp>
#include <ya/commands/spatial/SetMinSize1.hpp>
#include <ya/commands/spatial/SetMinSizeX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize¹>();
        w.property(UNSAFE, "min_size", &AMinSize¹::m_min_size);
        
        w.slot(UNSAFE, &AMinSize¹::on_set_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_set_min_sizeX);

        w.slot(UNSAFE, &AMinSize¹::on_add_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_add_min_sizeX);
        
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_sizeX);
    }
}

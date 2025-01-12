////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize2.hpp>
#include <ya/commands/spatial/AddSize2.hpp>
#include <ya/commands/spatial/AddSizeX.hpp>
#include <ya/commands/spatial/AddSizeY.hpp>
#include <ya/commands/spatial/MultiplySize.hpp>
#include <ya/commands/spatial/MultiplySize2.hpp>
#include <ya/commands/spatial/MultiplySizeX.hpp>
#include <ya/commands/spatial/MultiplySizeY.hpp>
#include <ya/commands/spatial/SetSize2.hpp>
#include <ya/commands/spatial/SetSizeX.hpp>
#include <ya/commands/spatial/SetSizeY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ISize²>();
        w.property(UNSAFE, "size", &ASize²::m_size);

        w.slot(UNSAFE, &ASize²::on_set_size2);
        w.slot(UNSAFE, &ASize²::on_set_sizeX);
        w.slot(UNSAFE, &ASize²::on_set_sizeY);

        w.slot(UNSAFE, &ASize²::on_add_size2);
        w.slot(UNSAFE, &ASize²::on_add_sizeX);
        w.slot(UNSAFE, &ASize²::on_add_sizeY);
        
        w.slot(UNSAFE, &ASize²::on_multiply_size);
        w.slot(UNSAFE, &ASize²::on_multiply_size2);
        w.slot(UNSAFE, &ASize²::on_multiply_sizeX);
        w.slot(UNSAFE, &ASize²::on_multiply_sizeY);
    }
}

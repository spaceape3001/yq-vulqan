////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize1.hpp>
#include <ya/commands/spatial/AddSize1.hpp>
#include <ya/commands/spatial/AddSizeX.hpp>
#include <ya/commands/spatial/MultiplySize.hpp>
#include <ya/commands/spatial/MultiplySize1.hpp>
#include <ya/commands/spatial/MultiplySizeX.hpp>
#include <ya/commands/spatial/SetSize1.hpp>
#include <ya/commands/spatial/SetSizeX.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.interface<ISize¹>();
        
        w.slot(&ASize¹::on_set_size1);
        w.slot(&ASize¹::on_set_sizeX);

        w.slot(&ASize¹::on_add_size1);
        w.slot(&ASize¹::on_add_sizeX);
        
        w.slot(&ASize¹::on_multiply_size);
        w.slot(&ASize¹::on_multiply_size1);
        w.slot(&ASize¹::on_multiply_sizeX);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AScale3.hpp>
#include <ya/commands/spatial/AddScale3.hpp>
#include <ya/commands/spatial/AddScaleX.hpp>
#include <ya/commands/spatial/AddScaleY.hpp>
#include <ya/commands/spatial/AddScaleZ.hpp>
#include <ya/commands/spatial/MultiplyScale.hpp>
#include <ya/commands/spatial/MultiplyScale3.hpp>
#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <ya/commands/spatial/MultiplyScaleY.hpp>
#include <ya/commands/spatial/MultiplyScaleZ.hpp>
#include <ya/commands/spatial/SetScale3.hpp>
#include <ya/commands/spatial/SetScaleX.hpp>
#include <ya/commands/spatial/SetScaleY.hpp>
#include <ya/commands/spatial/SetScaleZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IScale³>();
        
        w.slot(UNSAFE, &AScale³::on_set_scale3);
        w.slot(UNSAFE, &AScale³::on_set_scaleX);
        w.slot(UNSAFE, &AScale³::on_set_scaleY);
        w.slot(UNSAFE, &AScale³::on_set_scaleZ);

        w.slot(UNSAFE, &AScale³::on_add_scale3);
        w.slot(UNSAFE, &AScale³::on_add_scaleX);
        w.slot(UNSAFE, &AScale³::on_add_scaleY);
        w.slot(UNSAFE, &AScale³::on_add_scaleZ);
        
        w.slot(UNSAFE, &AScale³::on_multiply_scale);
        w.slot(UNSAFE, &AScale³::on_multiply_scale3);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleY);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleZ);
    }
}

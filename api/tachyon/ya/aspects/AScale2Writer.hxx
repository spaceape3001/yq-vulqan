////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AScale2.hpp>
#include <ya/commands/spatial/AddScale2.hpp>
#include <ya/commands/spatial/AddScaleX.hpp>
#include <ya/commands/spatial/AddScaleY.hpp>
#include <ya/commands/spatial/MultiplyScale.hpp>
#include <ya/commands/spatial/MultiplyScale2.hpp>
#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <ya/commands/spatial/MultiplyScaleY.hpp>
#include <ya/commands/spatial/SetScale2.hpp>
#include <ya/commands/spatial/SetScaleX.hpp>
#include <ya/commands/spatial/SetScaleY.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale²::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IScale²>();
        w.property(UNSAFE, "scale", &AScale²::m_scale).tag(kTag_Save);

        w.slot(UNSAFE, &AScale²::on_set_scale2);
        w.slot(UNSAFE, &AScale²::on_set_scaleX);
        w.slot(UNSAFE, &AScale²::on_set_scaleY);

        w.slot(UNSAFE, &AScale²::on_add_scale2);
        w.slot(UNSAFE, &AScale²::on_add_scaleX);
        w.slot(UNSAFE, &AScale²::on_add_scaleY);
        
        w.slot(UNSAFE, &AScale²::on_multiply_scale);
        w.slot(UNSAFE, &AScale²::on_multiply_scale2);
        w.slot(UNSAFE, &AScale²::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale²::on_multiply_scaleY);
    }
}

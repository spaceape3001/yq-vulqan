////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AScale2.hpp>
#include <ya/commands/scale/AddScale2.hpp>
#include <ya/commands/scale/AddScaleX.hpp>
#include <ya/commands/scale/AddScaleY.hpp>
#include <ya/commands/scale/MultiplyScale.hpp>
#include <ya/commands/scale/MultiplyScale2.hpp>
#include <ya/commands/scale/MultiplyScaleX.hpp>
#include <ya/commands/scale/MultiplyScaleY.hpp>
#include <ya/commands/scale/SetScale2.hpp>
#include <ya/commands/scale/SetScaleX.hpp>
#include <ya/commands/scale/SetScaleY.hpp>
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

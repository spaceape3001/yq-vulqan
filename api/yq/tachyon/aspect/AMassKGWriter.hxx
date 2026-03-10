////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/aspect/AMassKG.hpp>
#include <yq/tachyon/command/mass/AddMassKGCommand.hpp>
#include <yq/tachyon/command/mass/MultiplyMassCommand.hpp>
#include <yq/tachyon/command/mass/SetMassKGCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMassKG::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IMassKG>();
        w.property(UNSAFE, "mass", &AMassKG::m_mass).tag(kTag_Save).tag(kTag_Log);

        w.slot(UNSAFE, &AMassKG::on_add_mass_command);
        w.slot(UNSAFE, &AMassKG::on_multiply_mass_command);
        w.slot(UNSAFE, &AMassKG::on_set_mass_command);
    }
}

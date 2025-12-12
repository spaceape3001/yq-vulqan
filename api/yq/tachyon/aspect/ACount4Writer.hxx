////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ACount4.hpp>
#include <yq/tachyon/command/count/AddCount4Command.hpp>
#include <yq/tachyon/command/count/AddCountWCommand.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/AddCountZCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount4Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountWCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZCommand.hpp>
#include <yq/tachyon/command/count/SetCount4Command.hpp>
#include <yq/tachyon/command/count/SetCountWCommand.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCountZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ACount⁴::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<ICount⁴>();
        w.property(UNSAFE, "count", &ACount⁴::m_count).tag(kTag_Save);
        
        w.slot(UNSAFE, &ACount⁴::on_set_count4);
        w.slot(UNSAFE, &ACount⁴::on_set_countW);
        w.slot(UNSAFE, &ACount⁴::on_set_countX);
        w.slot(UNSAFE, &ACount⁴::on_set_countY);
        w.slot(UNSAFE, &ACount⁴::on_set_countZ);

        w.slot(UNSAFE, &ACount⁴::on_add_count4);
        w.slot(UNSAFE, &ACount⁴::on_add_countW);
        w.slot(UNSAFE, &ACount⁴::on_add_countX);
        w.slot(UNSAFE, &ACount⁴::on_add_countY);
        w.slot(UNSAFE, &ACount⁴::on_add_countZ);
        
        w.slot(UNSAFE, &ACount⁴::on_multiply_count);
        w.slot(UNSAFE, &ACount⁴::on_multiply_count4);
        w.slot(UNSAFE, &ACount⁴::on_multiply_countW);
        w.slot(UNSAFE, &ACount⁴::on_multiply_countX);
        w.slot(UNSAFE, &ACount⁴::on_multiply_countY);
        w.slot(UNSAFE, &ACount⁴::on_multiply_countZ);
    }
}

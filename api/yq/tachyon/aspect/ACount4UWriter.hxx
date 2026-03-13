////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ACount4U.hpp>
#include <yq/tachyon/command/count/AddCount4UCommand.hpp>
#include <yq/tachyon/command/count/AddCountWUCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/AddCountZUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount4UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountWUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZUCommand.hpp>
#include <yq/tachyon/command/count/SetCount4UCommand.hpp>
#include <yq/tachyon/command/count/SetCountWUCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCountZUCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ACount⁴U::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<ICount⁴U>();
        w.property(UNSAFE, "count", &ACount⁴U::m_count).tag(kTag_Save);
        
        w.slot(UNSAFE, &ACount⁴U::on_set_count4);
        w.slot(UNSAFE, &ACount⁴U::on_set_countW);
        w.slot(UNSAFE, &ACount⁴U::on_set_countX);
        w.slot(UNSAFE, &ACount⁴U::on_set_countY);
        w.slot(UNSAFE, &ACount⁴U::on_set_countZ);

        w.slot(UNSAFE, &ACount⁴U::on_add_count4);
        w.slot(UNSAFE, &ACount⁴U::on_add_countW);
        w.slot(UNSAFE, &ACount⁴U::on_add_countX);
        w.slot(UNSAFE, &ACount⁴U::on_add_countY);
        w.slot(UNSAFE, &ACount⁴U::on_add_countZ);
        
        w.slot(UNSAFE, &ACount⁴U::on_multiply_count);
        w.slot(UNSAFE, &ACount⁴U::on_multiply_count4);
        w.slot(UNSAFE, &ACount⁴U::on_multiply_countW);
        w.slot(UNSAFE, &ACount⁴U::on_multiply_countX);
        w.slot(UNSAFE, &ACount⁴U::on_multiply_countY);
        w.slot(UNSAFE, &ACount⁴U::on_multiply_countZ);
    }
}

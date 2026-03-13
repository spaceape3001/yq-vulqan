////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ACount3U.hpp>
#include <yq/tachyon/command/count/AddCount3UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/AddCountZUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount3UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZUCommand.hpp>
#include <yq/tachyon/command/count/SetCount3UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCountZUCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ACount³U::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<ICount³U>();
        w.property(UNSAFE, "count", &ACount³U::m_count).tag(kTag_Save);
        
        w.slot(UNSAFE, &ACount³U::on_set_count3);
        w.slot(UNSAFE, &ACount³U::on_set_countX);
        w.slot(UNSAFE, &ACount³U::on_set_countY);
        w.slot(UNSAFE, &ACount³U::on_set_countZ);

        w.slot(UNSAFE, &ACount³U::on_add_count3);
        w.slot(UNSAFE, &ACount³U::on_add_countX);
        w.slot(UNSAFE, &ACount³U::on_add_countY);
        w.slot(UNSAFE, &ACount³U::on_add_countZ);
        
        w.slot(UNSAFE, &ACount³U::on_multiply_count);
        w.slot(UNSAFE, &ACount³U::on_multiply_count3);
        w.slot(UNSAFE, &ACount³U::on_multiply_countX);
        w.slot(UNSAFE, &ACount³U::on_multiply_countY);
        w.slot(UNSAFE, &ACount³U::on_multiply_countZ);
    }
}

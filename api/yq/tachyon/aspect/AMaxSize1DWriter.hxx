////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMaxSize1D.hpp>
#include <yq/tachyon/command/size/AddMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize¹D::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMaxSize¹D>();
        w.property(UNSAFE, "max_size", &AMaxSize¹D::m_max_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &AMaxSize¹D::on_set_max_size1);
        w.slot(UNSAFE, &AMaxSize¹D::on_set_max_sizeX);

        w.slot(UNSAFE, &AMaxSize¹D::on_add_max_size1);
        w.slot(UNSAFE, &AMaxSize¹D::on_add_max_sizeX);
        
        w.slot(UNSAFE, &AMaxSize¹D::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize¹D::on_multiply_max_size1);
        w.slot(UNSAFE, &AMaxSize¹D::on_multiply_max_sizeX);
    }
}

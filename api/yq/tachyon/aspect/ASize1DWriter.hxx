////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ASize1D.hpp>
#include <yq/tachyon/command/size/AddSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize¹D::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ISize¹D>();
        w.property(UNSAFE, "size", &ASize¹D::m_size).def_value(kDefSize).tag(kTag_Save);
        
        w.slot(UNSAFE, &ASize¹D::on_set_size1);
        w.slot(UNSAFE, &ASize¹D::on_set_sizeX);

        w.slot(UNSAFE, &ASize¹D::on_add_size1);
        w.slot(UNSAFE, &ASize¹D::on_add_sizeX);
        
        w.slot(UNSAFE, &ASize¹D::on_multiply_size);
        w.slot(UNSAFE, &ASize¹D::on_multiply_size1);
        w.slot(UNSAFE, &ASize¹D::on_multiply_sizeX);
    }
}

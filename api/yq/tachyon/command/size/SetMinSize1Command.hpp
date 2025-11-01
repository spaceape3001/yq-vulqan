////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize¹Command, SizeCommand)
    public:
        SetMinSize¹Command(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize¹Command(const Header&);
        SetMinSize¹Command(const SetMinSize¹Command&, const Header&);
        ~SetMinSize¹Command();

    private:
        Size1D   m_size = ZERO;
        
        SetMinSize¹Command(const SetMinSize¹Command&) = delete;
        SetMinSize¹Command(SetMinSize¹Command&&) = delete;
        SetMinSize¹Command& operator=(const SetMinSize¹Command&) = delete;
        SetMinSize¹Command& operator=(SetMinSize¹Command&&) = delete;
    };
}

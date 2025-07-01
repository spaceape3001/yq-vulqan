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
    class SetSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize¹Command, SizeCommand)
    public:
        SetSize¹Command(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize¹Command(const Header&);
        SetSize¹Command(const SetSize¹Command&, const Header&);
        ~SetSize¹Command();

    private:
        Size1D   m_size = ZERO;
        
        SetSize¹Command(const SetSize¹Command&) = delete;
        SetSize¹Command(SetSize¹Command&&) = delete;
        SetSize¹Command& operator=(const SetSize¹Command&) = delete;
        SetSize¹Command& operator=(SetSize¹Command&&) = delete;
    };
}

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
    class SetMaxSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize¹Command, SizeCommand)
    public:
        SetMaxSize¹Command(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize¹Command(const Header&);
        SetMaxSize¹Command(const SetMaxSize¹Command&, const Header&);
        ~SetMaxSize¹Command();

    private:
        Size1D   m_size = ZERO;
        
        SetMaxSize¹Command(const SetMaxSize¹Command&) = delete;
        SetMaxSize¹Command(SetMaxSize¹Command&&) = delete;
        SetMaxSize¹Command& operator=(const SetMaxSize¹Command&) = delete;
        SetMaxSize¹Command& operator=(SetMaxSize¹Command&&) = delete;
    };
}

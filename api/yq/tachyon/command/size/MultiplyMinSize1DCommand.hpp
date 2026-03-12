////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize¹DCommand, SizeCommand)
    public:
        MultiplyMinSize¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyMinSize¹DCommand();
        MultiplyMinSize¹DCommand(const MultiplyMinSize¹DCommand&, const Header&);
        MultiplyMinSize¹DCommand(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyMinSize¹DCommand(const MultiplyMinSize¹DCommand&) = delete;
        MultiplyMinSize¹DCommand(MultiplyMinSize¹DCommand&&) = delete;
        MultiplyMinSize¹DCommand& operator=(const MultiplyMinSize¹DCommand&) = delete;
        MultiplyMinSize¹DCommand& operator=(MultiplyMinSize¹DCommand&&) = delete;
    };
}

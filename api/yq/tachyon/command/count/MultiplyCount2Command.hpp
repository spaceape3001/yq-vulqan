////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyCount²Command : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount²Command, CountCommand)
    public:
        MultiplyCount²Command(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        unsigned  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyCount²Command(const MultiplyCount²Command&, const Header&);
        MultiplyCount²Command(const Header&);
        ~MultiplyCount²Command();

    private:
        Vector2D  m_δ;
        
        MultiplyCount²Command(const MultiplyCount²Command&) = delete;
        MultiplyCount²Command(MultiplyCount²Command&&) = delete;
        MultiplyCount²Command& operator=(const MultiplyCount²Command&) = delete;
        MultiplyCount²Command& operator=(MultiplyCount²Command&&) = delete;
    };
}

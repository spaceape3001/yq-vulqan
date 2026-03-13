////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyCount¹Command : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount¹Command, CountCommand)
    public:
        MultiplyCount¹Command(const Header&, const Vector1U&);
    
        const Vector1U&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyCount¹Command();
        MultiplyCount¹Command(const MultiplyCount¹Command&, const Header&);
        MultiplyCount¹Command(const Header&);
    

    private:
        Vector1U  m_δ;
        
        MultiplyCount¹Command(const MultiplyCount¹Command&) = delete;
        MultiplyCount¹Command(MultiplyCount¹Command&&) = delete;
        MultiplyCount¹Command& operator=(const MultiplyCount¹Command&) = delete;
        MultiplyCount¹Command& operator=(MultiplyCount¹Command&&) = delete;
    };
}

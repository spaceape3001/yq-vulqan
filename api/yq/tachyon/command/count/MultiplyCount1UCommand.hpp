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
    class MultiplyCount¹UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount¹UCommand, CountCommand)
    public:
        MultiplyCount¹UCommand(const Header&, const Vector1U&);
    
        const Vector1U&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyCount¹UCommand();
        MultiplyCount¹UCommand(const MultiplyCount¹UCommand&, const Header&);
        MultiplyCount¹UCommand(const Header&);
    

    private:
        Vector1U  m_δ;
        
        MultiplyCount¹UCommand(const MultiplyCount¹UCommand&) = delete;
        MultiplyCount¹UCommand(MultiplyCount¹UCommand&&) = delete;
        MultiplyCount¹UCommand& operator=(const MultiplyCount¹UCommand&) = delete;
        MultiplyCount¹UCommand& operator=(MultiplyCount¹UCommand&&) = delete;
    };
}

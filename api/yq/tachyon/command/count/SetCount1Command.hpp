////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCount¹Command : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount¹Command, CountCommand)
    public:
        SetCount¹Command(const Header&, const Vector1U&);
    
        const Vector1U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount¹Command(const Header&);
        SetCount¹Command(const SetCount¹Command&, const Header&);
        ~SetCount¹Command();

    private:
        Vector1U   m_count = ZERO;
        
        SetCount¹Command(const SetCount¹Command&) = delete;
        SetCount¹Command(SetCount¹Command&&) = delete;
        SetCount¹Command& operator=(const SetCount¹Command&) = delete;
        SetCount¹Command& operator=(SetCount¹Command&&) = delete;
    };
}

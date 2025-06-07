////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplySizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeᶻCommand, SizeCommand)
    public:
        MultiplySizeᶻCommand(const Header&, double);
        
        static void init_info();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeᶻCommand(const MultiplySizeᶻCommand&, const Header&);
        MultiplySizeᶻCommand(const Header&);
        ~MultiplySizeᶻCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplySizeᶻCommand(const MultiplySizeᶻCommand&) = delete;
        MultiplySizeᶻCommand(MultiplySizeᶻCommand&&) = delete;
        MultiplySizeᶻCommand& operator=(const MultiplySizeᶻCommand&) = delete;
        MultiplySizeᶻCommand& operator=(MultiplySizeᶻCommand&&) = delete;
    };
}

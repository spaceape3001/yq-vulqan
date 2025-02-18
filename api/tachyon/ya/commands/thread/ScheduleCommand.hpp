////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ThreadCommand.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {

    /*! \brief Schedule NEW tachyons into thread
    
        This is for a batch import of tachyons (presumably from a save file)
        onto a new thread.  (So, no "Push/pull" mechanism here)
    */
    class ScheduleCommand : public ThreadCommand {
        YQ_OBJECT_DECLARE(ScheduleCommand, ThreadCommand)
    public:
        ScheduleCommand(const Header&, const std::vector<TachyonPtr>&);
        ScheduleCommand(const Header&, std::vector<TachyonPtr>&&);

        const std::vector<TachyonPtr>&  tachyons() const { return m_tachyons; }
        
        static void init_info();
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
    
        ScheduleCommand(const ScheduleCommand&, const Header&);
        ~ScheduleCommand();

    private:
        std::vector<TachyonPtr> m_tachyons;

        ScheduleCommand(const ScheduleCommand&) = delete;
        ScheduleCommand(ScheduleCommand&&) = delete;
        ScheduleCommand& operator=(const ScheduleCommand&) = delete;
        ScheduleCommand& operator=(ScheduleCommand&&) = delete;
    };
}

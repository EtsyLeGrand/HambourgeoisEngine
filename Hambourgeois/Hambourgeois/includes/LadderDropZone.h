#pragma once
#include <Component.h>
#include <Entity.h>

namespace hambourgeois
{
    class LadderDropZone : public Component
    {
    public:
        virtual ~LadderDropZone() = default;
        LadderDropZone();
        LadderDropZone(Entity* parent);

        /// <summary>
        /// Getter for the drop zone's linked ladder
        /// </summary>
        /// <returns>: the ladder's entity</returns>
        Entity* GetLinkedLadder() { return linkedLadder;  }
        /// <summary>
        /// Setter for the drop zone's linked ladder
        /// </summary>
        /// <param name="_ladder">: the ladder's entity</param>
        void SetLinkedLadder(Entity* _ladder) { linkedLadder = _ladder;  }

    private:
        Entity* linkedLadder = nullptr;
    };
}
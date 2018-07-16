/* State maintained during a spesh-aware frame walk. */
struct MVMSpeshFrameWalker {
    /* The current real MVMFrame that we are considering. */
    MVMFrame *cur_caller_frame;

    /* If we're doing a walk of outer frames too, the current outer frame that
     * we are considering starting from the caller frame. */
    MVMFrame *cur_outer_frame;

    /* Should we walk the outer chain hanging off each dynamic frame? */
    MVMuint8 visit_outers;

    /* Did we start iterating yet? */
    MVMuint8 started;

    /* Are we currently visiting the outer chain? */
    MVMuint8 visiting_outers;
};

void MVM_spesh_frame_walker_init(MVMThreadContext *tc, MVMSpeshFrameWalker *fw, MVMFrame *start,
        MVMuint8 visit_outers);
MVMuint32 MVM_spesh_frame_walker_next(MVMThreadContext *tc, MVMSpeshFrameWalker *fw);
MVMuint32 MVM_spesh_frame_walker_get_lex(MVMThreadContext *tc, MVMSpeshFrameWalker *fw,
        MVMString *name, MVMRegister **found_out, MVMuint16 *found_kind_out);
void MVM_spesh_frame_walker_cleanup(MVMThreadContext *tc, MVMSpeshFrameWalker *fw);

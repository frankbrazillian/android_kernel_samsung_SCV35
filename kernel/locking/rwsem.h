#ifdef CONFIG_RWSEM_SPIN_ON_OWNER
static inline void rwsem_set_owner(struct rw_semaphore *sem)
{
	sem->owner = current;
	smp_wmb();
}

static inline void rwsem_clear_owner(struct rw_semaphore *sem)
{
	sem->owner = NULL;
	smp_wmb();
}

#else
static inline void rwsem_set_owner(struct rw_semaphore *sem)
{
}

static inline void rwsem_clear_owner(struct rw_semaphore *sem)
{
}
#endif

__all__ = [
    'log',
    'init_log',
]

import logging
log = logging.getLogger("__PROJECT_NAME__")

def init_log(level):
    try:
        import coloredlogs

        log_fmt = "%(asctime)s,%(msecs)03d %(programname)s[%(process)d] %(levelname)s: %(message)s"
        coloredlogs.install(level=level, fmt=log_fmt, logger=log)
    except:
        log_fmt = "%%(asctime)s %s[%%(process)d] %%(levelname)s: %%(message)s" % ( 
            "__PROJECT_NAME__",
        )
        handler = logging.StreamHandler()
        handler.setFormatter(logging.Formatter(log_fmt))
        log.setLevel(level)
        log.addHandler(handler)



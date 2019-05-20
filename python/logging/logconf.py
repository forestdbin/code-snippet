import logging
import logging.config

logconf = {
    'version': 1,
    'root': {
        'level': 'NOTSET',
        'handlers': [ 'default', 'file', ],
    },
    'loggers': {
        'application': {
            'level': 'NOTSET',
            'handlers': [ 'default', 'file', ],
            'propagate': 0,
        },
    },
    'handlers': {
        'default': {
            'level': 'NOTSET',
            'formatter': 'default',
            'class': 'logging.StreamHandler',
            'stream': 'ext://sys.stderr',
        },
        'file': {
            'level': 'NOTSET',
            'formatter': 'default',
            'class': 'logging.FileHandler',
            'filename': 'debug.log',
            'mode': 'w',
        },
    },
    'formatters': {
        'default': {
            'format': '%(asctime)s %(levelname)-8s - %(message)s'
        },
    },
}

logging.config.dictConfig(logconf)

logger = logging.getLogger()

logger.debug('debug')
logger.info('info')
logger.warning('warning')
logger.error('error')
logger.critical('critical')

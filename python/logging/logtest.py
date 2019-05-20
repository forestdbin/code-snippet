import logging
import logging.config

logging.config.fileConfig('log.conf')

logger = logging.getLogger()

logger.debug('debug')
logger.info('info')
logger.warning('warning')
logger.error('error')
logger.critical('critical')

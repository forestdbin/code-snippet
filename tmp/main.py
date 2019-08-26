import logging
import logging.config
import sys
import decimal
from decimal import Decimal

logging.config.fileConfig('log.conf')
logger = logging.getLogger()

decimal.getcontext().prec = 4

goodsInfo = {
    'soup': Decimal('0.65'),
    'bread': Decimal('0.80'),
    'milk': Decimal('1.30'),
    'apples': Decimal('1.00'),
}

decimal0 = Decimal('0')
decimal1_00 = Decimal('1.00')

if __name__ == '__main__':
    logger.debug('program start')
    basket = [arg.lower() for arg in sys.argv[1:] if arg.lower() in goodsInfo]
    subtotal = sum([goodsInfo[item] for item in basket], decimal0)
    logger.debug('Subtotal: $%s', subtotal.quantize(decimal1_00))
    discounts = {
        'apples': basket.count('apples') * goodsInfo['apples'] * Decimal('0.1'),
        'bread': min(basket.count('bread'), basket.count('soup') // 2) * goodsInfo['bread'] * Decimal('0.5'),
    }
    for k, v in discounts.items():
        if k == 'apples' and v != decimal0:
            logger.debug('Apples 10%% off: ($%s)', v.quantize(decimal1_00))
        if k == 'bread' and v != decimal0:
            logger.debug('Bread 50%% off: ($%s)', v.quantize(decimal1_00))
    if not any(discounts.values()):
        logger.debug('(no offers available)')
    total = subtotal - sum(discounts.values(), decimal0)
    logger.debug('Total: $%s', total.quantize(decimal1_00))

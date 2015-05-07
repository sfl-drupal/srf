<?php

/**
 * Callback function to alter text_long widget.
 * @param  array $element Element to be altered
 */
function srf_text_long_alter_widget(&$element) {
  $element['value']['#title'] = theme('srf_field_label', array(
    'title' => $element['value']['#title'],
  ));
}

/**
 * Callback function to alter text_with_summary widget.
 * @param  array $element Element to be altered
 */
function srf_text_with_summary_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter entityreference widget.
 * @param  array $element Element to be altered
 */
function srf_entityreference_alter_widget(&$element) {
  $element['target_id']['#title'] = theme('srf_field_label', array(
    'title' => $element['target_id']['#title'],
  ));
}

/**
 * Callback function to alter taxonomy_term_reference widget.
 * @param  array $element Element to be altered
 */
function srf_taxonomy_term_reference_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter image widget.
 * @param  array $element Element to be altered
 */
function srf_image_alter_widget(&$element) {
  foreach ($element as $id => &$elem) {
    $elem['#title'] = theme('srf_field_label', array(
      'title' => $elem['#title'],
    ));
  }
}
